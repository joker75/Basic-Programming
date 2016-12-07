/*******************************************
 * Assignment IV: This program can receive a
 * string of integers from the command line,
 * store it into an array, and check if it's
 * in an ascending order.
 * Created by:	Victor Nguyen on 9/22/2016.
 * 				vdn140030
 *				CS 2336.005
 *				Fall 2016
 *******************************************/
import java.util.InputMismatchException;
import java.util.ArrayList;

public class ascendingOrderCheck
{
    public static void main (String [] args)
    {
        // Defines variables
        ArrayList <Integer> integers = new ArrayList<Integer>();
        int SIZE = args.length;		// Size of the array as well as Array List
        boolean check;

        // Input Validation for mismatched values
        try
        {
            for (int i = 0; i < SIZE; i++)
            {
                integers.add( Integer.parseInt(args[i]) );
            }
        }

        catch (InputMismatchException ex)
        {
            System.out.println("INVALID INPUT");
            System.exit(0);
        }

        catch (NumberFormatException ex)
        {
            System.out.println("INVALID INPUT!");
            System.exit(0);
        }
        // Function call to check for ascending order
        check = isSorted(integers);

        // Print results
        System.out.print("\nThe string of integers is");
        if (check)
        {
            System.out.println(" in an ascending order. ");
        }
        else
        {
            System.out.println(" not in an ascending order. ");
        }
        System.out.print("Thank you for using the program.\n");

        // Clear memory
        integers.clear();
    }

    /************************************
     This function checks for an ascending
     order. Returns true or false.
     ************************************/
    private static boolean isSorted(ArrayList<Integer> list)
    {
        // Defines variable
        int SIZE = list.size();
        for (int j = 0; j < SIZE -1; j++)
        {
            if (list.get(j) > list.get(j+1) )	// If the current element
            {									// is bigger than the next
                return false;					// return false
            }
        }
        return true;
    }
}
