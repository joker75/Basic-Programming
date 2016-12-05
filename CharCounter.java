/********************************************
 * Assignment VI: This program can read input
 * from a file character by character, keep
 * track of which alphanumeric characters are
 * in the file, and display onto the console
 * how many of each are used. All other 
 * characters and whitespace are disregarded.
 *
 * Created by   Victor Nguyen on 10/12/2016.
 * 			    vdn140030
 *				CS 2336.005
 *				Fall 2016
 ******************************************/
import java.io.*;
import java.util.Scanner;
public class CharCounter {
    public static void main (String [] args) throws IOException {
	// Defines variables
	Scanner input = new Scanner (System.in);
	Scanner info;
	int[] counter = new int[127];   // Defines the character array
									// Stores all known characters

	try{
		// Prompts user for a file name
		System.out.print("Please enter a file name (with the extension): ");
		info = new Scanner(new BufferedReader(new FileReader(input.next())));

		// Call function to count the characters
		Input(info, counter);

		// Call function to display results
		Display (counter);
	}
	catch(FileNotFoundException e){
		System.out.println(e.getClass());
	}
	finally {
		// Closes file
		input.close();
		}
    }

/***********************************************
* This function receives input from the file and
* keeps track of the characters by incrementing
* the index in the array. The following array is
* passed by reference; therefore, this function
* can have the return type as void.
* The following ASCII values are associated
* with these characters. For example, the
* ASCII value 65 represents 'A".
* 48-57 :: 0-9
* 65-90 :: A-Z
* 97-122 :: a-z
************************************************/
private static void Input(Scanner iFile, int [] array)
	{
	while (iFile.hasNext()) {
		// Define string variables
		String s = iFile.next();
		int length = s.length();

		// Reading from the file while incrementing the counter
		for (int i = 0; i < length; i++) {
			// converts characters to integers, which are both ASCII
			// values as well as the counter indexes
			array[(int) s.charAt(i)]++;
			}
		}
	}

/*******************************************
 * This function displays the characters.
 * The following ASCII values are associated
 * with these characters. For example, the
 * ASCII value 65 represents 'A".
 * 48-57 :: 0-9
 * 65-90 :: A-Z
 * 97-122 :: a-z
 *******************************************/
private static void Display (int[] results)
	{
	// This for loop will display the results
	// to the console
	for (int i = 48; i < 123; i++) {
		if (i == 58)        // If at 9
			i = 65;         // Skips to A
		else if (i == 91)	// If at Z
			i = 97;         // Skips to a
		if (results[i] != 0)
			System.out.println("Number of " + (char) i + "'s: " + results[i]);
		}
	}
}
