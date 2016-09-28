/*****************************************
 * Assignment III: This program can convert
 * unsigned decimal integers into binary
 * numbers. This program will not accept
 * signed numbers, floating-pointing
 * numbers, and other inappropriate
 * characters. Additionally, it will
 * validate input for these conditions.
 *
 * Created by:  Victor Nguyen
 *              vdn140030
 *              CS 2336.005
 *              Fall 2016
 ****************************************/

import java.util.InputMismatchException;// Check for inappropriate characters
import java.util.Scanner;               // Receive keyboard input

public class DecToBinary {
    public static void main (String[] args){
        // Defines variables
        Scanner input = new Scanner(System.in);
        int decimal = 0;
        String binaryDigits;

        // INPUT VALIDATION
        try
        {
            System.out.print("Please enter a decimal value, and I will tell you the binary conversion: ");
            decimal = input.nextInt();
            if(decimal < 1)     // Checks for negative integers
                throw new IllegalArgumentException("INVALID INPUT. No negative numbers!");
        }

        // EXCEPTIONS AND END PROGRAM
        catch (IllegalArgumentException ex)     // Catches negative number input
        {
            System.out.println(ex);
            System.exit(0);
        }
        catch (InputMismatchException ex)       // Catches mismatched data types
        {
            System.out.println("INVALID INPUT");
            System.exit(0);
        }

        // BINARY CONVERSION
        binaryDigits = convert(decimal);

        // Display results
        System.out.println("Your result is: " + binaryDigits);
    }

    /***********************************
    * This function converts the decimal
    * value to the binary conversion.
    ***********************************/
    private static String convert(int num)
    {
        // Defines variables
        int remainder;
        String conversion = "";

        // Build the binary digit string
        while (num != 0)
        {
            remainder = num % 2;    // Grabs the remainder of the digit
            if (remainder == 1)
                conversion += "1";  // Adds a 1 to the string
            else
                conversion += "0";  // Adds a 0 to the string
            num /= 2;               // Divide by 2 and continue the loop
        }

        // Returns the reversed string as the answer
        return new StringBuffer(conversion).reverse().toString();
    }
}
