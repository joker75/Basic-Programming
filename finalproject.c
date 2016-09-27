/**************************************************
This program reads functions of polynomials
with/without trigonometric functions from the input
file and writes the derivatives of the input to
the output file. This program can handle fractional
coefficients.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1325.002

**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define SIZE 100
#define SIZE2 6

struct Fraction{
    int num;
    int den;
};
typedef struct Fraction fract;

// Function prototypes
void getInput(char *, FILE *);
void store(char [], fract [], fract [], fract [], fract [], int, int, int);
char *trigStore(int len, int place, char *ptr, fract trig[], int copy, int value, int value2);
void calculate(FILE *, fract [], fract [], fract [], fract [], int, int, int);
int GCD (int a, int b);

int main()
{
    // Defines variables
    FILE *ifp = fopen("functions.txt", "r"), *ofp = fopen("derive.txt", "w");
    char input[SIZE];
    fract exp[21];          // Index of 0 will be for a constant,
                            //   which should never be used since the derivative of any
                            //   constant value will always be 0.
                            //   1-10 will be for positive exponents.
                            //   11-20 will be for negative exponents.
    fract sinArray[SIZE2], cosArray[SIZE2], tanArray[SIZE2];
    int multSin, multCos, multTan;          // Keeps track of multiple copies
                                            //   of the same trig function
    if (ifp)
        {
            while ( !feof(ifp) )
            {
                int k;

                // Initialization/reset the character array
                for (k = 0; k < SIZE; ++k)
                    input[k] = '\0';

                // Initialization/reset the exponent array
                for (k = 0; k < 21; ++k)
                {
                    exp[k].num = 0;
                    exp[k].den = 0;
                }

                // Initialization/reset the trig arrays
                for (k = 0; k < SIZE2; ++k)
                {
                    sinArray[k].num = 0;
                    sinArray[k].den = 0;
                    cosArray[k].num = 0;
                    cosArray[k].den = 0;
                    tanArray[k].num = 0;
                    tanArray[k].den = 0;
                }

                // Initialization/reset the multiple trig function counters
                multSin = 0, multCos = 0, multTan = 0;

                getInput(input, ifp);
                store(input, exp, sinArray, cosArray, tanArray, multSin, multCos, multTan);
                calculate(ofp ,exp, sinArray, cosArray, tanArray, multSin, multCos, multTan);
            }
        }
    else
        puts("ERROR! File not found.");

    fclose(ifp);
    fclose(ofp);
    return 0;
}

/********************************************************************
This function stores the input into a character array with a pointer.
********************************************************************/
void getInput(char *process, FILE *ifp)
{
    // Defines variables
    char c;
    int i = 0;
    while( (c = fgetc(ifp)) != '\n' )
    {
        *(process + i) = c;
        ++i;
        if (c ==EOF)
            break;
    }

    // Adds the terminating null character to the string
    *(process + i) = '\0';
}

/*********************************************
This function searches through the input array
and stores the coefficients to the appropriate
exponential index.
*********************************************/
void store(char process[], fract storage[], fract sin[], fract cos[], fract tan[], int multSin, int multCos, int multTan)
{
    int length = strlen(process);   // Gets the length of the string
                                    //   before the null terminating character
    char *ptr = process;            // The pointer will access the contents of
                                    //   the string

    // Flags
    int negCoeff = 1, noCoeff = 1;  // 1 = found

    int i, hold, hold2 = 1, powerValue; // Respectively: for loop counter, coefficient holders,
                                        //   exponential value
    for (i = 0; i < length; ++i)
    {
        if (*(ptr + i) == ' ' || *(ptr + i) == '+')     // Skips spaces and + signs
        {
            noCoeff = 1;
            continue;
        }

        if (*(ptr + i + 1) == '\0' )
            break;

        else if (*(ptr + i) == '(')                     // Finds the fraction (#/#)
        {
            hold = strtol(ptr + i + 1, &ptr, 0);
            length -= ( floor(log10( hold )) + 1 );         // Length readjustment based on
                                                            //   the length of the numerator
            hold2 = strtol(ptr + 1, &ptr, 0);
            length -= ( floor(log10( hold2 )) + 1 );        // Length readjustment based on
                                                            //   the length of the denominator
            hold *= negCoeff;
            i = -1;                                         // Counter and flags reset
            negCoeff = 1;
            noCoeff = 0;
            ++ptr;                                          // Skips the closing parenthesis )
        }
        else if (*(ptr + i) == '-' || *(ptr + i) == '-')// Looks for the - sign
        {                                           //   subtraction/negative
            noCoeff = 1;
            negCoeff = -1;
        }

        else if ( isdigit( *(ptr + i) )  )              // Finds the coefficient
        {
            hold = strtol(ptr + i, &ptr, 0);
            length -= ( floor(log10( hold )) + 1 );         // Length readjustment based on
                                                            //   the length of the coefficient
            hold *= negCoeff;
            i = -1;                                          // Counter and flags reset
            negCoeff = 1;
            noCoeff = 0;

        }

        else if((*(ptr + i) == 'x' && noCoeff) ||
                (*(ptr + i) == 's' && noCoeff) ||
                (*(ptr + i) == 'c' && noCoeff) ||
                (*(ptr + i) == 't' && noCoeff) )            // x values or trig functions without a coefficient
        {                                                   //   are assumed to be 1 or -1
            hold = 1 * negCoeff;
            negCoeff = 1;
            noCoeff = 0;
        }

        if ( *(ptr + i) == 'x' && *(ptr + i + 1) != '^')    // Checks for #x
        {
            storage[1].num = hold;                          // index/power of 1
            storage[1].den = hold2;
            negCoeff = 1;                                   // After storage, flags must be
            noCoeff = 1;                                    //   reset
            hold2 = 1;
        }
        if ( *(ptr + i) == 'x' && *(ptr + i + 1) == '^')    // Other polynomials
        {
            i+=2;
            int negExp = 1;
            if (*(ptr + i) == '-' || *(ptr + i) == '-')     // Checks for negative exponents
            {                                               //   by looking for the negative sign
                negExp = -1;                                //   and readjusting the pointer to the
                ++i;                                        //   digit after the negative sign
            }
            powerValue = strtol(ptr + i, &ptr, 0) * negExp;
            negExp = 1;                                     // negative exponent reset
            if (powerValue > 0)
                {
                    storage[powerValue].num = hold;
                    storage[powerValue].den = hold2;
                    length -= ( floor(log10( powerValue )) + 1 ) ;  // Length readjustment
                }
            else // powerValue < 0
                {
                    storage[ (powerValue * -1) + 10].num = hold;
                    storage[ (powerValue * -1) + 10].den = hold2;
                    length -= ( floor(log10( powerValue * -1 )) + 1 );  // Length readjustment
                }

                i = -1;                                             // Counter reset
                                                                    //   and counteracts the update
                negCoeff = 1;                                       // After storage, flags must be
                noCoeff = 1;                                        //   reset
                hold2 = 1;
        }

        // Checks for the coefficients for the sine function
        else if ( *(ptr + i) == 's')
        {
            ptr = trigStore(length, i, ptr, sin, multSin, hold, hold2);
            length = strlen(ptr);
            i = -1;                                         // Counter reset
                                                            //   and counteracts the update
            negCoeff = 1;                                   // After storage, flags must be
            noCoeff = 1;                                    //   reset
            hold2 = 1;
            multSin+=2;                                     // Counts the number of sin functions
        }

        // Checks for the coefficients for the cosine function
        else if ( *(ptr + i) == 'c')
        {
            ptr = trigStore(length, i, ptr, cos, multCos, hold, hold2);
            length = strlen(ptr);
            i = -1;                                         // Counter reset
                                                            //   and counteracts the update
            negCoeff = 1;                                   // After storage, flags must be
            noCoeff = 1;                                    //   reset
            hold2 = 1;
            multCos+=2;                                     // Counts the number of cos functions
        }

        // Checks for the coefficients for the tangent function
        else if ( *(ptr + i) == 't')
        {
            ptr = trigStore(length, i, ptr, tan, multTan, hold, hold2);
            length = strlen(ptr);
            i = -1;                                         // Counter reset
                                                            //   and counteracts the update
            negCoeff = 1;                                   // After storage, flags must be
            noCoeff = 1;                                    //   reset
            hold2 = 1;
            multTan+=2;                                     // Counts the number of tan functions
        }
    }
}

/**************************************************************************
This function can be reused for storing values for trigonometric functions.
**************************************************************************/
char *trigStore(int len, int place, char *ptr, fract trig[], int copy, int value, int value2)
{
    place +=4;
    int negTrigCoeff = 1;

    if (*(ptr + place) == '-' || *(ptr + place) == '-')     // Checks for negative coefficients
    {                                                       //   by looking for the negative sign
        negTrigCoeff = -1;                                  //   and readjusting the pointer to the
        ++place;                                            //   digit after the negative sign
    }

    if (*(ptr + place) == 'x' )                             // Checks for #sin x and #sin -x
    {
        trig[copy].num = value;
        trig[copy].den = value2;
        trig[copy+1].num = 1 * negTrigCoeff;
        trig[copy+1].den = 1;
        ptr+=(place + 1 );
    }

    else                                            // Otherwise, #sin #x and #sin -#x
    {
        trig[copy].num = value;
        trig[copy].den = value2;
        trig[copy+1].num = strtol(ptr + place, &ptr, 0) * negTrigCoeff;
        trig[copy+1].den = 1;
        ++ptr;
    }

    return ptr;
}


/*****************************************************
This function calculates and writes the derivatives to
the output file.
*****************************************************/
void calculate(FILE *oFp, fract exponentialValues[], fract sine[], fract cosine[], fract tangent[], int copySin, int copyCos, int copyTan)
{
    fract *derive = exponentialValues;  // Exponential array pointer,
    int i;                              // exponential array counter
    int simpNum, simpDen;              // Respectively: simplified numerator and denominator

    // This for loop writes the positive exponential
    //   derivatives to the output file
    for (i = 10; i > 2; --i)
    {
        if ( (derive + i)->num == 0 )
            continue;

        simpNum = (derive + i)->num * i / GCD (abs((derive + i)->num), (derive + i)->den);
        simpDen = (derive + i)->den / GCD (abs((derive + i)->num), (derive + i)->den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }


        if ( simpDen == 1 )
        {
            if ( simpNum == 1 )
                fprintf (oFp, "+x^%d", i - 1);
            else if ( simpNum == -1)
                fprintf (oFp, "-x^%d", i - 1);
            else
                fprintf (oFp, "%+dx^%d", simpNum ,i - 1);
        }
        else
            fprintf (oFp, "+(%+d/%d)x^%d", simpNum, simpDen, i - 1);
    }

    // Checks for the exponential value of 2
    if ( (derive + i) ->num != 0 )
    {
        simpNum = (derive + i)->num * i / GCD (abs((derive + i)->num), (derive + i)->den);
        simpDen = (derive + i)->den / GCD (abs((derive + i)->num), (derive + i)->den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

    if ( simpDen == 1 )
    {
        if ( simpNum == 1 )
            fprintf (oFp, "+x");
        else if ( simpNum == -1)
            fprintf (oFp, "-x");
        else
            fprintf (oFp, "%+dx", simpNum);
    }

    else
        fprintf (oFp, "+(%+d/%d)x", simpNum, simpDen);
    }
    --i;

    // Checks for the exponential value of 1
    if ( (derive + i)->num != 0 )
    {
        simpNum = (derive + i)->num * i / GCD (abs((derive + i)->num), (derive + i)->den);
        simpDen = (derive + i)->den / GCD (abs((derive + i)->num), (derive + i)->den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

    if ( simpDen == 1 )
    {
        if ( simpNum == 1 )
            fprintf (oFp, "+1");
        else if ( simpNum == -1)
            fprintf (oFp, "-1");
        else
            fprintf (oFp, "%+d", simpNum);
    }

    else
        fprintf (oFp, "+(%+d/%d)", simpNum, simpDen);
    }

    // This for loop writes the negative exponential
    //   derivatives to the output file
    for (i = 11; i < 21; ++i)
    {
        if ( (derive + i)->num == 0 )
            continue;

        simpNum = (derive + i)->num * (i - 10) * -1 / GCD (abs((derive + i)->num), (derive + i)->den);
        simpDen = (derive + i)->den / GCD (abs((derive + i)->num), (derive + i)->den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

        if ( simpDen == 1 )
        {
            if ( simpNum == 1 )
                fprintf (oFp, "+x^%d", ((i - 10) * -1) - 1 );
            else if ( simpNum == -1)
                fprintf (oFp, "-x^%d", ((i - 10) * -1) - 1);
            else
                fprintf (oFp, "%+dx^%d", simpNum , ((i - 10) * -1) - 1);
        }

        else
            fprintf (oFp, "+(%+d/%d)x^%d", simpNum, simpDen, ((i - 10) * -1) - 1);
    }

    // Writes the trig functions in the order of sine, cosine, and sec^2
    int num2, k = 1;

    while (cosine[k].num != 0)
    {
        num2 = cosine[k].num;

        simpNum = -1 * cosine[k-1].num * cosine[k].num / GCD (abs(cosine[k].num), cosine[k-1].den);
        simpDen = cosine[k-1].den / GCD (abs(cosine[k].num), cosine[k-1].den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

        // Coefficients of 1 or -1 are omitted
        if ( simpDen == 1 )
        {
            if ( simpNum == 1 )
                fprintf (oFp, "+sin");
            else if ( simpNum == -1)
                fprintf (oFp, "-sin");
            else
                fprintf (oFp, "%+dsin", simpNum);
        }

        else
            fprintf(oFp,"+(%+d/%d)sin ", simpNum, simpDen);

        if (num2 == 1)
            fprintf(oFp,"x");
        else if (num2 == -1)
            fprintf(oFp,"-x");
        else
            fprintf(oFp, "%+dx", num2);
        //fprintf(oFp, "%+dsin %dx", -1 * cosine[0] * cosine[1], cosine[1]);
        k+=2;   // Checks for other copies of the cosine function
    }

    k = 1;
    while (sine[k].num != 0)
    {
        num2 = sine[k].num;

        simpNum = sine[k-1].num * sine[k].num / GCD (abs(sine[k].num), sine[k-1].den);
        simpDen = sine[k-1].den / GCD (abs(sine[k].num), sine[k-1].den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

        // Coefficients of 1 or -1 are omitted
        if ( simpDen == 1 )
        {
            if ( simpNum == 1 )
                fprintf (oFp, "+cos");
            else if ( simpNum == -1)
                fprintf (oFp, "-cos");
            else
                fprintf (oFp, "%+dcos", simpNum);
        }

        else
            fprintf(oFp,"+(%+d/%d)cos ", simpNum, simpDen);

        if (num2 == 1)
            fprintf(oFp,"x");
        else if (num2 == -1)
            fprintf(oFp,"-x");
        else
            fprintf(oFp, "%+dx", num2);
        //fprintf(oFp, "%+dcos %dx", sine[0] * sine[1], sine[1]);
        k+=2;   // Checks for other copies of the sine function
    }

    k = 1;
    while (tangent[k].num != 0)
     {
        num2 = tangent[k].num;

        simpNum = tangent[k-1].num * tangent[k].num / GCD (abs(tangent[k-1].num * tangent[k].num), tangent[k-1].den);
        simpDen = tangent[k-1].den / GCD (abs(tangent[k-1].num * tangent[k].num), tangent[k-1].den);

        if (simpNum / simpDen == 1 || simpNum / simpDen == -1)
        {
            simpNum /= simpDen;
            simpDen = 1;
        }

        // Coefficients of 1 or -1 are omitted
        if ( simpDen == 1 )
        {
            if ( simpNum == 1 )
                fprintf (oFp, "+sec^2");
            else if ( simpNum == -1)
                fprintf (oFp, "-sec^2");
            else
                fprintf (oFp, "%+dsec^2", simpNum);
        }

        else
            fprintf(oFp,"+(%+d/%d)sec^2 ", simpNum, simpDen);

        if (num2 == 1)
            fprintf(oFp,"x");
        else if (num2 == -1)
            fprintf(oFp,"-x");
        else
            fprintf(oFp, "%+dx", num2);
        //fprintf(oFp, "%+dsec^2 %dx",tangent[0] * tangent[1], tangent[1]);
        k+=2;   // Checks for other copies of the tangent function
    }

    fprintf(oFp,"\n");
}

/*****************************************************
This function helps simplify the fractions, if needed.
*****************************************************/
int GCD (int a, int b)
{
    // Error checking
    if (a==0)
        return b;
    else if (b==0)
        return a;

    // Returns the final factor
    else if (a==b)
        return a;

    // Recursion
    else if (a > b)
        return GCD (b, a%b);
    else // (b > a)
        return GCD (a, b%a);
}
