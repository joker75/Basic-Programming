/***************************************
This program performs basic mathematical
computations with complex numbers after
validating the input from the user.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1325.002
***************************************/
#include "stdio.h"
#include "float.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#define SIZE 100

// Function prototypes
void getInput(char *);
int isComplete(char *, int);                // Validates the string
int isValid(char *, int);
int isNum(char *, int);                     // Excludes the spaces and validates the values
void decide(const char [], char *, int);    // Determines the operation
void computeComplex(const char [], const double [], char); // Imaginary/Complex calculation
int GCD (int a, int b);
int main()
{
    // Defines variables
    char input[SIZE], *ptr;

    // Infinite loop for input
    while (1)
    {
        puts("Please enter a valid mathematical expression (or \"exit\" to end the program): ");
        getInput(input);
        puts(input);

        if (!(strcmp(input, "exit") ) )
        {
            printf("\n\nEXITING THE PROGRAM. Thanks for using the program!\n\n");
            exit(0);
        }

        // Defines variables to check for each individual character
        int length = strlen(input) + 1;
        ptr = input;
        int check1 = isComplete(ptr, length);
        int check2 = isValid(ptr, length);
        int check3 = isNum(ptr, length);
        printf("%d\t%d\t%d\n", check1, check2, check3);

        if (check1 && check2 && check3)
        {
            decide(input, ptr, length);
        }
        else
            puts("ERROR! INVALID INPUT. PLEASE TRY AGAIN.");
    }
    return 0;
}

/********************************************************************
This function stores the input into a character array with a pointer.
********************************************************************/
void getInput(char *data)
{
    // Defines variables
    char c;
    int i = 0;
    while( i < SIZE - 1 && (c = getchar()) != '\n' )
    {
        *(data + i) = c;
        ++i;
    }

    // Adds the terminating null character to the string
    *(data + i) = '\0';
}

/*************************************************
This function validates the input from the user.
0 represents an invalid string, while 1 represents
the other. This is part 1 of the input validation
process.
*************************************************/
int isComplete(char *point, int length)
{
        // Initialization & re-initialization for each repetition
        int op = 0;
        int parenthesis = 0;        // increment for '(' and decrement for ')'
        int pipe = 0;               // 2 for a complete set
        int i;
        for ( i = 0; i < length-1; ++i )
        {
            // Valid
            if (*(point + i)  == '\0')
            return 1;

            if (    !isdigit( *(point + i) )   )
            {
                if (*(point + i) == '(')
                    ++parenthesis;
                else if (*(point + i) == ')')
                    --parenthesis;
                else if (*(point + i) == '|')
                    ++pipe;
                else if ( *(point + i) == '+' || *(point + i) == '-' || *(point + i) == '*' || *(point + i) == '/')
                    op = 1;
                else if ( *(point + i) == 'i' || *(point + i) == ' ' || *(point + i) == '.')
                    continue;
                else // Invalid letters and special characters
                    return 0;

            }

            if ( isdigit(*(point + i) ) )
            {
                int j = i + 1;
                while (*(point + j) == ' ')
                {
                    ++j;
                    if ( isdigit( *(point + j) ) )  // Space between two numbers
                        return 0;
                    if (  *(point + j) == 'i' )     // Space between a number and i
                        return 0;
                }
                continue;
            }

            //   Operator within the absolute value bars
            if (op && pipe > 1)
                return 0;

            if (op)
            {
                int k = i + 1;
                if (*(point + k) == '+' || *(point + k) == '-' || *(point + k) == '*' || *(point + k) == '/')
                    return 0;
                while (*(point + k) == ' ')
                {
                    ++k;
                    // Space between two operators
                    if (*(point + k) == '+' || *(point + k) == '-' || *(point + k) == '*' || *(point + k) == '/')
                        return 0;
                    // Space between hyphen and number in absolute value bars
                    if ( isdigit( *(point + k) ) && pipe)
                        return 0;
                }
                --op;
                continue;
            }
            // Excess parenthesis
            if (parenthesis > 1 || parenthesis < 0)
                return 0;
        }

        if (parenthesis == 1)
            return 0;
        //   One pipe bar or too many pipe bars
        if (pipe == 1 || pipe > 2)
            return 0;

        // Valid
        return 1;
}

/************************************************
This function checks for the imaginary or complex
expression of the string as well as inappropriate
operators within the absolute value bars.
This is part 2 of the input validation process.
************************************************/
int isValid(char *pt, int limit)
{
    int foundCorI = 0;              // 0 for only single input of complex or imaginary
                                    //   1 for valid input
    int abs = 0;                    // 1 for a pipe bar found
    int counter;
    for ( counter = 0; counter < limit-1; ++counter )
        {
            int imaginary = 0;      //1 for imaginary, 2 for complex
            int parenFlag = 0;
            if ( *(pt + counter) == '(' )
            {
                ++parenFlag;
                int addSym = 0;
                int l = counter + 1;
                if (*(pt + l) == ')')
                    return 0;
                while (*(pt + l) != '\0')
                {
                    if ( *(pt + l) == '+' )     // Checks for too many addition symbols in the parenthesis
                        ++addSym;
                    if (  *(pt + l) == 'i' )
                        imaginary = 1;
                    if ( addSym == 2)
                        return 0;
                    if (  (*(pt + l) == '*' || *(pt + l) == '/') )
                        return 0;
                    if (  (*(pt + l) == '-' || *(pt + l) == '+') && imaginary )
                        return 0;
                    if (*(pt + l) == ')' && !imaginary)
                        return 0;
                    if (*(pt + l) == ')')
                    {
                        foundCorI = 1;
                        ++parenFlag;
                        counter = l;
                        break;
                    }
                    ++l;
                }
            }

            // Checks for parenthesis before and after the imaginary/complex
            else if ( *(pt + counter) == 'i' && parenFlag != 2)
                return 0;
            else if ( *(pt + counter) == '|' )
                abs = 1;
            else if ( *(pt + counter) == '|' && (parenFlag == 1)  )
                return 0;
            else if ( ( *(pt + counter) == '+' || *(pt + counter) == '*' || *(pt + counter) == '/') && abs == 1 )
                return 0;
            else    // for spaces and digits
                continue;
            while (parenFlag == 2 && (*(pt + counter + 1) == ' ' || *(pt + counter + 1) == '\0') && foundCorI == 0 )
            {
                ++counter;
                if (*(pt + counter) == '\0')
                    return 0;
            }
        }

    // Valid
    return 1;
}

/***********************************************
This function checks for the values greater than
99 with less than 3 decimal places. This is part
3 of the input validation process.
***********************************************/
int isNum(char * ptr, int size)
{
    int decCounter = 0; // Checks for too many decimal points
    int numCounter = 0; // Checks for too many places before
                        //   and after the decimal point
    int operation = 0;  // Checks for existence of operators
    int i;
    for (i = 0; i < size - 1; ++i)
    {
        if (isdigit( *(ptr + i) ) )
            numCounter++;
        if (  *(ptr + i) == '.'  )
        {
            decCounter++;
            numCounter = 0;
        }
        if (numCounter > 2|| decCounter > 1)
            return 0;
        int j = i;
        while ( isspace( *(ptr + j) ) )
        {
            ++j;
            if (*(ptr + j) == '\0' )
                return 0;
        }

        if ( *(ptr + i) == '+' || *(ptr + i) == '-' || *(ptr + i) == '*' || *(ptr + i) == '/' || *(ptr + i) == '|' || *(ptr + i) == 'i')
        {
            numCounter = 0;
            decCounter = 0;
            operation = 1;
        }
    }

    if (!operation)
        return 0;

    // Valid
    return 1;
}

/******************************************************
This function decides what kind of operation is needed.
******************************************************/
void decide(const char Input[], char *Pointer, int len)
{
    char op;
    int findOp = 0;                 // This is primarily for imaginary/complex
                                    // calculations
    double Bmatrix[2] = {0,0};      // Basic computations matrix
    double Cmatrix[4] = {0,0,0,0};  // Complex/imaginary computations matrix
    int i = 0, j = 0;               // Basic Matrix and Complex Matrix counters
    int k;                          // Traversing counter
    int foundCorI = 0;              // 1 for found, -1 for not found
    int foundParen = 0;
    int absFlag = 0;
    int absComplete = 0;
    int CabsComplete = 0;
    for (k = 0; k < len - 1; ++k)
    {
        if (*(Pointer + k) == ' ')
            continue;
        if (*(Pointer + k) == '|')
           {
               int m = k + 1;
               while (*(Pointer + m) != '\0')
               {
                   if (*(Pointer + m) == 'i')
                   {
                       ++absFlag;
                       foundCorI = 1;
                       break;
                   }
                   ++m;
               }
                ++absFlag;
                if (foundCorI ==0)
                    foundCorI = -1;
                continue;
           }

        if (   (isdigit( *(Pointer + k) ) || *(Pointer + k) == '-' ) && foundCorI == -1 )
        {
            Bmatrix[0] = atof(Pointer + k );
            absComplete = 1;
        }

        if ( ( (  *(Pointer + k) == '+' || *(Pointer + k) == '-' || *(Pointer + k) == '*' || *(Pointer + k) == '/' ) ) && foundParen == 0 )
        {
            op = *(Pointer + k);
        }

        if (   isdigit( *(Pointer + k) ) )
        {
            int num;
            if (*(Pointer + k - 1) == '-')
                num = -1 * atof(Pointer+k);
            else
                num = atof(Pointer+k);

            while ( isdigit( *(Pointer + k) ) || *(Pointer + k) == '.' )
                ++k;
            --k;        // This counteracts the update expression
                        //   from the for loop

            if (*(Pointer + k + 1) == 'i')
                Bmatrix[1] = num;
            else
                Bmatrix[0] = num;
            ++i;
        }
        if (*(Pointer + k + 1) == 'i')
        {
            if ( op == '+' || !isdigit(*(Pointer + k)) )
                Bmatrix[1] = 1;
            else if ( op == '-' || !isdigit(*(Pointer + k)) )
                Bmatrix[1] = -1;
            Cmatrix[ j ] = Bmatrix[0];
            Cmatrix[ j+1 ] = Bmatrix[1];
            j+=2;   // Complex Matrix completion counter
            i = 0;  // Basic Matrix completion reset
            Bmatrix[0] = 0;
            Bmatrix[1] = 0;
            foundCorI = 1;
            CabsComplete = 1;
        }

        /*if (foundCorI == 1 && absFlag == 0)
        {
            Cmatrix[j] = Bmatrix[0];
            j+=2;
        }*/

        if ( *(Pointer + k) == '(' )
                foundParen = 1;
        if ( *(Pointer + k) == ')' )
            findOp = 1;
        if ( (  *(Pointer + k) == '+' || *(Pointer + k) == '-' || *(Pointer + k) == '*' || *(Pointer + k) == '/' || *(Pointer + k) == '(' ) && findOp)
        {
            op = *(Pointer + k);
            findOp = 0;
            if (op == '(')
                    op = '*';
        }
        // RESULTS

        // Absolute Values
        if ( foundCorI == -1 && absFlag && absComplete)
        {
            printf("%s=%.2lf\n", Input, fabs( Bmatrix[0] ));
            return;
        }
        if( foundCorI == 1 && absFlag && CabsComplete )
        {
            printf("%s=%.2lf\n", Input, fabs( pow( pow(Cmatrix[0], 2) + pow(Cmatrix[1], 2), 0.5)    )     );
            return;
        }

        // Basic Matrix Completion
        if (i == 2 && absFlag == 0 && foundParen == 0)
        {
            switch (op)
            {
                case '+':
                    printf("%s=%.2lf\n", Input, Bmatrix[0] + Bmatrix[1] );
                    break;
                case '-':
                    printf("%s=%.2lf\n", Input, Bmatrix[0] - Bmatrix[1] );
                    break;
                case '*':
                    printf("%s=%.2lf\n", Input, Bmatrix[0] * Bmatrix[1] );
                    break;
                case '/':
                    printf("%s=%.2lf\n", Input, Bmatrix[0] / Bmatrix[1] );
                    break;
            }
            return;
        }

        // Complex Matrix Completion
        if (j == 4)
        {
            computeComplex(Input, Cmatrix, op);
            return;
        }

    }
}

void computeComplex(const char Input[], const double matrix[], char operation)
{
    int divider = 1;
    if ( operation == '+')
        printf("%s=(%.2lf) + (%.2lf)i\n", Input, matrix[0] + matrix[2], matrix[1] + matrix[3] );
    else if ( operation == '-')
        printf("%s=(%.2lf) + (%.2lf)i\n", Input, matrix[0] - matrix[2], matrix[1] - matrix[3] );

    else if ( operation == '*' && (matrix[1] == 0 || matrix[3] == 0) )
        printf("%s=(%.2lf) + (%.2lf)i\n", Input, matrix[0] * matrix[2], matrix[1] * matrix[3] );
    else if ( operation == '*' && !(matrix[1] == 0 || matrix[3] == 0) )
        printf("%s=(%.2lf)\n", Input, (matrix[0] * matrix[2]) - (matrix[1] * matrix[3]) );

    // Division
    else if ( operation == '/' && (matrix[0] == 0 && matrix[1] != 0 && matrix[2] != 0 && matrix[3] != 0) )
    {
        if( GCD( (int)matrix[1], (int)matrix[2])  == GCD( (int)matrix[1], (int)matrix[3]))
            divider = GCD( (int)matrix[1], (int)matrix[2]);
        printf("%s=(%.2lfi)/( (%.2lf) + (%.2lfi) )\n", Input, matrix[1]/divider, matrix[2]/divider, matrix[3]/divider );
    }

    else if ( operation == '/' && (matrix[0] != 0 && matrix[1] == 0 && matrix[2] != 0 && matrix[3] != 0) )
    {
        if( GCD( (int)matrix[0], (int)matrix[2])  == GCD( (int)matrix[0], (int)matrix[3]))
            divider = GCD( (int)matrix[0], (int)matrix[2]);
        printf("%s=(%.2lf)/( (%.2lf) + (%.2lfi) )\n", Input, matrix[0]/divider, matrix[2]/divider, matrix[3]/divider );
    }

    else if ( operation == '/' && (matrix[0] != 0 && matrix[1] != 0 && matrix[2] == 0 && matrix[3] != 0) )
    {
        if( GCD( (int)matrix[0], (int)matrix[3])  == GCD( (int)matrix[1], (int)matrix[3]))
            divider = GCD( (int)matrix[0], (int)matrix[2]);
        printf("%s=( (%.2lf) + (%.2lfi) ))/(%.2lfi)\n", Input, matrix[0]/divider, matrix[1]/divider, matrix[3]/divider );
    }

    else if ( operation == '/' && (matrix[0] != 0 && matrix[1] != 0 && matrix[2] != 0 && matrix[3] == 0) )
    {
        if( GCD( (int)matrix[0], (int)matrix[2])  == GCD( (int)matrix[1], (int)matrix[2]))
            divider = GCD( (int)matrix[0], (int)matrix[2]);
        printf("%s=( (%.2lf) + (%.2lfi) ))/(%.2lf)\n", Input, matrix[0]/divider, matrix[1]/divider, matrix[2]/divider );
    }
    else
    {
        printf("%s=( (%.2lf) + (%.2lfi) )/(%.2lf)\n", Input, (matrix[0] * matrix[2])+ (matrix[1]* -1 *matrix[3]), (matrix[1] * -1 * matrix[3])+ (matrix[1]* -1 *matrix[2]), pow(matrix[2], 2) + pow(matrix[3], 2)  );
    }
    return;
}

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
    else // (b < a)
        return GCD (a, b%a);
}
