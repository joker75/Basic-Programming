/*******************************************
 * Assignment VII: This program can receive
 * a string from the user and display all
 * of the permutations of that one string.
 * Created by:  Victor Nguyen on 10/18/2016.
 *              vdn140030
 *				CS 2336.005
 *				Fall 2016
 *******************************************/
import java.util.InputMismatchException;
import java.util.Scanner;
public class StringPermutations {
    public static void main (String [] args){
    // Defines variables
    Scanner input = new Scanner (System.in);

        // TRY AND CATCH INVALID INPUT
    try {
        System.out.print("Please enter a string: ");
        String str = input.next();
        int length = str.length();
        char[] inputChar = str.toCharArray();       // Since strings are immutable,
                                                    // managing a string is better
                                                    // done with a character array
        // Call recursion function here
        perm(inputChar, 0, length - 1);
    }

    // EXCEPTIONS AND END PROGRAM
    catch (InputMismatchException ex) {
        System.out.println(ex + ": INVALID INPUT!\nProgram exiting.");
        System.exit(0);
    }
}

    /******************************************************
    * This helper function displays all of the permutations
    * of a string by constantly changing the characters of
    * the starting and ending index. Once the starting and
    * ending index are the same, that array will be
    * displayed on the console.
    ******************************************************/
    private static void perm(char [] array, int start, int end){
        int i;
        if (start == end)                   // Base case
            System.out.println(array);      // Display the array
        else {
            for (i = start; i <= end; i++) {// Run a loop through the entire array from start to end
                swap(array, start, i);
                perm (array, start+1, end);
                swap(array, start, i);      // Backtrack by reversing
                                            // the swap
            }
        }
    }

    /*********************************************************
    * This function will swap the two characters of the array.
    *********************************************************/
    private static void swap(char [] letters , int first, int last){
        char temp = letters [first];
        letters[first] = letters[last];
        letters[last] = temp;
    }
}