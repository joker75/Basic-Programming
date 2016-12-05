/*************************************
NOTE: THIS PROGRAM IS DIFFERENT FROM
THE JAVA PROGRAMS.

This program receives linear equations
from the user, performs Gauss-Jordan
elimination, and displays the values
of the variables x, y, and z.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1325.002
*************************************/
#include <stdio.h>
#include <float.h>  // Floating point values could be used as input
#define COL 4       // x, y, z, and a constant value are the 4 columns

// Function prototypes
int input(float [][COL] );
void Results(float [][COL], int );
void swap(float [][COL], int );
void multiply(float [][COL], int );
void add(float [][COL], int );
int isComplete(float [][COL], int );
void solution(float [][COL], int);

int main()
{
    // Defines the sentinel variable that checks for user repetitions
    int row = 0;

    do
    {
        //Defines variables
        int menuchoice;

        //Defines the input array
        float inputArray[4][COL];

        //Prompts the user with the first menu
        printf("%s","\n\t1) Input Linear Equations\n\t2) Perform Row Operations\n\t3) Exit\n\nPlease enter a menu option: ");
        scanf("%d", &menuchoice);

        // Exit statement
        if (menuchoice == 3)
            break;

        // Input validation
        else if (menuchoice == 2 && row == 0)
            puts("\nPlease input a set of linear equations prior to performing row operations.");

        // Performs row operations
        else if(menuchoice == 2 && row != 0)
            {
            // Initialize an array of 3 pointers to functions that will perform
            //   specific row operations
            void (*f[3])( float [row][COL], int ) = {swap, multiply, add};

            // Defines the variable to hold the user's menu choice
            size_t choice;

            // Gets input
            printf("%s", "\n\t0) Swap Rows\n\t1) Multiply a Row\n\t2) Add Two Rows\n\t3) Exit\n\nPlease enter a number from 0 to 2. ");
            scanf("%d", &choice);

            while(choice >=0 && choice < 3)
                {
                // Calls one of the 3 options the user has selected.
                (*f[choice])(inputArray, row);

                // Displays the results
                Results(inputArray, row);

                // Gets the next input
                printf("%s", "\n\t0) Swap Rows\n\t1) Multiply a Row\n\t2) Add Two Rows\n\t3) Exit\n\nPlease enter a number from 0 to 2, or 3 to exit. ");
                scanf("%d", &choice);
                }

                puts("Ending the row operations function.");
            }
        else if(menuchoice == 1)
            row = input(inputArray);

    }while(1);  //Infinite do-while loop

    puts("\nThanks for using the program!");

    return 0;
}

/***********************************************
This function gets the user input for the rows.
The program will then define the array with the
rows, ask the user for the linear equations, and
return the number of rows back to int main for
further menu usage.
***********************************************/
int input(float userData [][COL])
{
    int SIZE;

    // Gets the number of rows from the user
    printf("%s", "How many rows of linear equations do you need? ");
    scanf("%d", &SIZE);

    // Error checking: rows cannot be greater than 4
    while(SIZE > 4 || SIZE < 0)
    {
        printf("%s", "\nERROR! Rows cannot be greater than 4 nor less than 0.\nPlease enter a valid number of rows. ");
        scanf("%d", &SIZE);
    }

    // Defines the pointer to input data to the array
    float *inputPtr = userData[0];

    // For loop reads in the linear equations and sorts them
    //   into the array
    int i;                              // Counter
    char var1, var2, var3;              // x, y, and z variables
    float hold1, hold2, hold3, hold4;   // Coefficients
    for(i = 0; i < SIZE * 4; i += 4 )
    {
        // Prompts the user to input linear equations
        printf("Please enter %d row(s) of linear equations.\nHit enter after each linear equation entered.\n", SIZE);
        //         ax+by+cz=d
        scanf("%f%c%f%c%f%c=%f", &hold1, &var1, &hold2, &var2, &hold3, &var3, &hold4);

        // The value of the constant will be placed in the row + 3 element of the array
        *(inputPtr + i + 3) = hold4;

        // Sorts the array with var1 and hold1
        switch (var1)
        {
            case 'x':
                *(inputPtr + i) = hold1;
                break;
            case 'y':
                *(inputPtr + i + 1) = hold1;
                break;
            case 'z':
                *(inputPtr + i + 2) = hold1;
        }

        // Sorts the array with var2 and hold2
        switch (var2)
        {
            case 'x':
                *(inputPtr + i) = hold2;
                break;
            case 'y':
                *(inputPtr + i + 1) = hold2;
                break;
            case 'z':
                *(inputPtr + i + 2) = hold2;
        }

        // Sorts the array with var3 and hold3
        switch (var3)
        {
            case 'x':
                *(inputPtr + i) = hold3;
                break;
            case 'y':
                *(inputPtr + i + 1) = hold3;
                break;
            case 'z':
                *(inputPtr + i + 2) = hold3;
        }
    }

    // Outputs the sorted array
    puts("\n\nYour sorted array is: ");
    Results( userData, SIZE );

    // Returns the value of row back to int main for further
    //   menu use
    return SIZE;
}

/**********************************************
This function displays the values of the array.
A pointer is used here.
**********************************************/
void Results(float output[][COL], int row)
{
    // Initializes the display pointer
    float *displayPtr = output[0];

    puts("\nResults:\n");

    // Displays the contents of the array
    int i;
    for (i = 0; i < row * 4; i += 4)
        printf("(%f)x+(%f)y+(%f)z=%f\n", *(displayPtr + i), *(displayPtr + i + 1), *(displayPtr + i + 2), *(displayPtr + i + 3) );
}

/*********************************************************
This function swaps two rows that the user wishes to swap.
*********************************************************/
void swap(float data[][COL], int row)
{
    // Initializes the pointer and defines variables
    float *ptr = data[0];
    int swapRow, swap_Row;
    float hold;

    printf("%s", "Enter the first row you want to swap. ");
    scanf("%d", &swapRow);
    printf("%s", "Enter the second row you want to swap. ");
    scanf("%d", &swap_Row);

    // Error checking for rows that don't exist
    while(swapRow > row || swap_Row > row)
    {
        printf("%s", "\n\nERROR! One of the rows you entered is invalid.\n"
               "You cannot access a row greater than that of what you had inputted\nat the beginning of this program.\n"
               "Please re-enter the first row you want to swap. ");
        scanf("%d", &swapRow);
        printf("%s", "Please re-enter the second row you want to swap. ");
        scanf("%d", &swap_Row);
    }
    // Swaps values 4 times
    int counter;
    for(counter = 0; counter < 4; ++counter)
    {
        hold = *(ptr + swapRow * 4 - 4 + counter);
        *(ptr + swapRow * 4 - 4 + counter) = *(ptr + swap_Row * 4 - 4 + counter);
        *(ptr + swap_Row * 4 - 4 + counter) = hold;
    }
}

/************************************************************
This function multiplies a linear equation by a scalar value.
************************************************************/
void multiply(float array [][COL], int row)
{

    // Defines variables and initializes the pointer
    int rowChoice;
    float scalar, *point = array[0];

    // Prompts the user for which row to multiply and by how much
    printf("%s", "\nWhich row do you wish to multiply? ");
    scanf("%d", &rowChoice);

    // Error checking for rows that don't exist
    while(rowChoice > row)
    {
        printf("%s", "\n\nERROR! One of the rows you entered is invalid.\n"
               "You cannot access a row greater than that of what you had inputted\nat the beginning of this program.\n"
               "\nWhich row do you wish to multiply? ");
        scanf("%d", &rowChoice);
    }
    // Checking function to make sure the user can't
    //   interfere with a complete row
    if (isComplete(array, rowChoice) )
        {
            printf("This row is complete. Returning to the row operations menu screen. ");
            return;
        }

    // Otherwise, the multiply function continues
    printf("%s", "\nBy what scalar multiple? ");
    scanf("%f", &scalar);

    // Multiplies the selected linear equation by that scalar
    //   value
    int i;
    for (i = 0; i < 4; i++)
        *(point + rowChoice * 4 - 4 + i) *= scalar;

    // Notifies the user that if this row is now complete
    //   the user is prevented from multiplying this row
    //   by a scalar value
    if (isComplete(array, rowChoice) )
    {
        printf("\nRow %d is now complete. You cannot multiply this row anymore.", rowChoice);
        solution(array, rowChoice);
    }
}

/*********************************************************
This function asks which two rows to add and which row the
result will replace. Additionally, a reduced row echelon
checking function is needed here.
*********************************************************/
void add(float values[][COL], int row )
{
    // Defines variables and initializes the pointer
    int addRow, add_Row, replace;
    float *pointer = values[0];

    printf("%s", "What's the first row you want to add? ");
    scanf("%d", &addRow);
    printf("%s", "What's the second row you want to add? ");
    scanf("%d", &add_Row);
    printf("%s", "What row do you want to replace? ");
    scanf("%d", &replace);

    // Error checking for rows that don't exist
    while(addRow > row || add_Row > row || replace > row)
    {
        printf("%s", "\n\nERROR! One of the rows you entered is invalid.\n"
               "You cannot access a row greater than that of what you had inputted\nat the beginning of this program.\n"
               "What's the first row you want to add? ");
        scanf("%d", &addRow);
        printf("%s", "What's the second row you want to add? ");
        scanf("%d", &add_Row);
        printf("%s", "What row do you want to replace? ");
        scanf("%d", &replace);

    }
    int i;
    for (i = 0; i < 4; ++i)
        *(pointer + replace * 4 - 4 + i) = *(pointer + addRow * 4 - 4 + i) + *(pointer + add_Row * 4 - 4 + i);
}

/*****************************************************************
This function checks for the reduced row echelon form for one row.
It only checks for x, y, and z. The constant is disregarded. The
boolean value of 1 returned from this function will prevent the
user from multiplying that row by a scalar value. 0 represents
an incomplete row, while 1 represents a complete row.
*****************************************************************/
int isComplete(float array[][COL], int select)
{
    // Defines variables and initializes pointer
    int count1 = 0, i;
    float *pointing = array[0] + select * 4 - 4;
    for (i = 0; i < 3; ++i)
    {
        if (*(pointing + i) == 1)
            count1++;
        else if(*(pointing + i) == 0)
            continue;
        else    // *(pointing + i) != 0
            return 0;
    }
        if (count1 > 1)
            return 0;
        else
            return 1;
}

/****************************************************
Assuming that the row selected has been solved, this
function lets the user know what the solution is for
one variable.
****************************************************/
void solution(float coeff[][COL], int chosenRow)
{
    // Defines variables and initializes pointer
    float *pointed = coeff[0] + chosenRow * 4 - 4;

    // Lets the user know which variable has been solved
    int j;
    for (j = 0; j < 3; ++j)
    {
        if (j == 0 && *(pointed + j) == 1)
            printf("\nx = %f\n", *(pointed + 3) );
        else if (j == 1 && *(pointed + j) == 1 )
            printf("\ny = %f\n", *(pointed + 3) );
        else if (j == 2 && *(pointed + j) == 1 )
            printf("\nz = %f\n", *(pointed + 3) );
    }
}
