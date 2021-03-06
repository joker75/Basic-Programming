/**************************************************
 * ASSIGNMENT IX: This program receives 10 integers
 * from the user, stores them into a Binary Search
 * Tree, deletes the root, reconfigures the tree,
 * and displays the paths from leaf to root.
 * Note: a leaf is a node without any children.
 *
 *
 * Test Case: 106 101 100 102 103
 *              104 110 107 108 111
 * Created by:  Victor Nguyen on 11/28/2016.
 *              vdn140030
 *              CS 2336.005
 **************************************************/
import jdk.internal.util.xml.impl.Input;

import java.util.*;
public class Source {
    private static final int MAX = 10;
    public static void main (String [] args){
        // Defines variables
        ArrayList path = new ArrayList<>();
        Integer [] numbers = new Integer[MAX];
        Scanner input = new Scanner(System.in);

        // Prompts user
        System.out.print("Please enter 10 integers: ");

        // Stores data
        // Validates for Input Mismatch Exceptions
		do{
			int i = 0;
			try
			{
				for (; i < MAX; i++) {numbers[i] = input.nextInt();}
				// If the program manages to accept all valid integers,
				// then the array complete, and valid can now be true
				// to exit the loop
				if (i == MAX)
			    	valid = true;
			}

			// Catches invalid input
			catch(InputMismatchException e){
			System.out.println("Try again. (Input must be valid integers)\n" 
						+ e + "\nPlease enter 10 new integers.");
			valid = false;		// If this catch block is reached, input is NOT
						// valid! Therefore, this do-while loop repeats
			input.nextLine();	// Discard current input
			}
		} while(!valid);       		// Break from the loop when all input is VALID
        
        // Creates a BST based on the user input
        BST<Integer> intTree = new BST<>(numbers);

        // Deletes the root
        // REQUIRES STATIC CASTING ON THE ELEMENT OF THE ROOT
        intTree.delete( (Integer)intTree.getRoot().element);

        // Display results
        System.out.println("The preorder traversal is after deleting the root:");
        intTree.preorder();
        System.out.println("\n\nThe paths from leaf to root are:");

        // Add paths to an array
        for (int j = 0; j < MAX; j++){
            path.add(intTree.getPath(numbers[j]));
        }

        // Print everything
        for (int j = 0; j < MAX; j++){
            if (path.get(j) == null)        // Omit the null paths
                continue;
            System.out.println(path.get(j));
        }
    }
}
