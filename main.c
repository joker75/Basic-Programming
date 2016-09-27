/***********************************
This program calculates the angle
between two vectors. The two vectors
will be inputted as two sets of
coordinate points separated by a
space. The program will display the
angle using the second set of
coordinates as the starting point.
The program will end if the
coordinates entered are 0,0 for both
sets.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1325.002
***********************************/
#include <stdio.h>
#include <float.h>
#include <math.h>
#define PI 3.14159

// Function prototype
float calcAngle(float , float);

int main()
{
    // Defines variables
    float x1, y1, x2, y2;

    do
    {
        // Prompts the user for input
        printf("\nPlease enter two sets of coordinates, or (0,0) (0,0) \nto end the program: ");
        scanf("(%f,%f) (%f,%f)", &x1, &y1, &x2, &y2);

        // Ends the program
        if ( (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) ) {
            break;
        }

        // Calculates the angle with respect to the Cartesian
        //   coordinate system
        float angle1 = calcAngle(x1, y1), angle2 = calcAngle(x2, y2);

        // Displays the angles with respect to the Cartesian
        //   coordinate system
        printf("\nAngle 1: %f degrees\nAngle 2: %f degrees", angle1, angle2);

        // Searches for the correct angle to start with
        if (angle1 > angle2){
            // Displays the normal results
            printf("\nThe angle between the two vectors is %f.\n", angle1-angle2);
        }
        else // angle1 < angle2
        {
            // Displays the results for reflex angles
            printf("\nThe angle between the two vectors is %f.\n", angle1-angle2 + 360);
        }

        // Forces the program to wait for the next input
        fflush(stdin);


    // Endless loop unless the user enters the end program coordinates
    } while( 1 );

    // Exiting statement
    puts("\nThank you for using the program!");
    return 0;
}

/***********************************************
This function calculates the angle for a vector.
The value returned from this function will be an
angle in radians.
***********************************************/
float calcAngle(float x, float y)
{
    if (x >= 0 && y >= 0)         // First Quadrant
        return atan(y/x) * 180.0/ PI ;
    else if (x == 0 && y > 0)     // 90 degree mark
        return 90;
    else if (x < 0 && y > 0)    // Second Quadrant
        return (atan(y/x) + PI) * 180.0/ PI ;
    else if (y == 0 && x < 0)     // 180 degree mark
        return 180;
    else if (x < 0 && y < 0)    // Third Quadrant
        return (atan(y/x) + PI) * 180.0/ PI ;
    else if (x == 0 && y < 0)     // 270 degree mark
        return 270;
    else    // x > 0 && y < 0   // Fourth Quadrant
        return (atan(y/x) + 2 * PI) * 180.0/ PI ;
}

