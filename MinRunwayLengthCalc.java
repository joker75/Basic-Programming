import java.util.Scanner;

/****************************************
 * This program can calculate the minimum
 * runway length. It will take input from
 * the user and display the result.
 * Created by Victor on 8/24/2016.
 ***************************************/


public class MinRunwayLengthCalc {
    public static void main (String[] args){
        Scanner input = new Scanner (System.in);

        // Velocity input
        System.out.println("Please enter a velocity (m/s): ");
        double velocity = input.nextDouble();

        // Acceleration input
        System.out.println("Please enter an acceleration (m/s^2): ");
        double accel = input.nextDouble();

        // Calculation
        double length = (velocity * velocity) / (2 * accel);

        // Display result
        System.out.println("Your minimum runway length is: " + length + " m");
    }
}
