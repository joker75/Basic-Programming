/********************************
 * Assignment V: This main method receives
 * input, constructs a Linear Equations
 * object, checks if the equation is
 * solvable, and returns a solution.
 * Created by Victor Nguyen on 9/25/2016.
 * 					vdn140030
 *					CS 2336.005
 *					Fall 2016
 ********************************/

import java.util.InputMismatchException;
import java.util.Scanner;
public class Assignment5_vdn140030
{
    public static void main (String[] args)
    {
        // Defines and initializes variables
        Scanner input = new Scanner (System.in);
		double num1, num2, num3, num4, num5, num6;
		num1 = num2 = num3 = num4 = num5 = num6 = 0;

        // Any input mismatch will be caught here
		try{
		System.out.print("Enter a, b, c, d, e, and f: ");
		num1 = input.nextDouble();
		num2 = input.nextDouble();
		num3 = input.nextDouble();
		num4 = input.nextDouble();
		num5 = input.nextDouble();
		num6 = input.nextDouble();
		}
    
		// EXCEPTIONS AND END PROGRAM
		catch (InputMismatchException ex)
		{
			System.out.println(ex + ": INVALID INPUT!\nProgram exiting.");
			System.exit(0);
		}
		
		// Construct the object
		LinearEquation linEq = new LinearEquation(num1, num2, num3, num4, num5, num6);

        // Check if the equation is solvable by calling the class's method
        // Print results
		if ( linEq.isSolvable() )
			System.out.println("x is " + linEq.getX() + " and y is " + linEq.getY() );
		else
			System.out.println("The equation has no solution.");
		System.out.println("Thank you for using this program.");
	}
}
