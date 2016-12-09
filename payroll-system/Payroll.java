/**********************************
 * This payroll system provides the
 * user with entering in data for
 * employees.
 * Created by:  Victor on 12/8/2016.
 *              vdn140030
 *              CS 2336.005
 *              FALL 2016
 *********************************/
import java.io.*;
import java.lang.*;
import java.util.*;
public class payroll {
    // Static scanner object for multiple uses
    private static Scanner input = new Scanner(System.in);

    public static void main(String [] args){
        // Defines variables
        Employee employee_1 = new Employee();
        Employee employee_2 = new Employee();
        Employee employee_3 = new Employee();
        int choice = 0;     // Allows the user to
                            // choose options on the menu
        ArrayList<Employee> workers = new ArrayList<>();
        workers.add(employee_1);
        workers.add(employee_2);
        workers.add(employee_3);

        //========MENU DISPLAY========\\
        do{
            System.out.println("Welcome to the General Payroll System\nIt offers 3 options.\n"
                    + "============================\n"
                    + "1. Document Employee Pay\n"
                    + "2. End the Program.\n"
                    + "Please enter a number to begin.");

            // VALIDATE CHOICES
            try {
                choice = input.nextInt();
                choice = validate(choice);
            }

            catch(InputMismatchException e){
                System.out.println("Try again. Integers only. ");
                input.nextLine();	// Discard current input
                choice = 0;         // Reset to 0 for new input
            }
            switch (choice){
                case 1:
             		// call input function
                    INPUT(workers);

              	    // call the file writing function
                    write(workers);
                    break;
                case 2:
               	    break; // End the program

            }   // End of switch block
        }while (choice != 2);   // End of do-while block

        System.out.println("Thank you for using this system!");
    }

    /**************************************************
     * This function validates input with while loops *
     *************************************************/
    private static int validate(int num){
        while (num < 1 || num > 2){
            System.out.print("INVALID INPUT. Please enter an option listed above (1 or 2): " );
            num = input.nextInt();
        }

        // Returns valid menu options
        return num;
    }
    /*********************************************
    * This function accepts input from the user. *
    *********************************************/
    private static void INPUT(ArrayList<Employee> e){
        // Creates a dummy variable to validate input
        String tempS;

        // DATA ENTERING PROCEDURE
        for (int i = 0; i < e.size(); i++){

            System.out.println("Please enter data for Employee " + (i + 1));

            // FULL NAME
            System.out.print("Full name: ");
            tempS = input.nextLine();
            e.get(i).setFullName(tempS);

            // ID INPUT VALIDATION
            System.out.print("Please enter an ID (8 integers): ");
            tempS = input.nextLine();
            while(!isNumeric(tempS) || tempS.length() != 8){
                System.out.print("Invalid ID. Please enter an ID with 8 integers: ");
                tempS = input.nextLine();
            }
            e.get(i).setID(tempS);  // Accepted if valid

            // HOURLY RATE
            System.out.print("Please enter an hourly rate: ");
            tempS = input.nextLine();
            while(!isNumeric(tempS)){
                System.out.print("Invalid rate. Please make sure it is positive. ");
                tempS = input.nextLine();
            }
            e.get(i).setHourlyPay(Double.parseDouble(tempS));   // Accepted if valid

            // NUMBER OF HOURS
            System.out.print("Please enter the number of hours worked: ");
            tempS = input.nextLine();
            while(!isNumeric(tempS) || Double.parseDouble(tempS) > 40){
                System.out.print("Invalid number. Please make sure it is positive "
                        + "and below 40 hours. ");
                tempS = input.nextLine();
            }
            e.get(i).setWorkHours(Double.parseDouble(tempS));   // Accepted if valid
        }
    }

    /*********************************************************
    * This function checks if the string contains only numbers
    * by seeing if the string can be converted into floating
     * point values.
    *********************************************************/
    private static boolean isNumeric(String str)
    {
        // If the string can be converted
        // into integers, the string is fine.
        try{
            Double num = Double.parseDouble(str);
            if (num < 0)
                throw new NumberFormatException();
        }
        // If not, the string contains non-numeric
        // characters. Also checks for negative
        // numbers.
        catch(NumberFormatException ex){
            return false;
        }
        return true;
    }

    /***************************************
    * This function writes to an output file
    * to save the data.
    ***************************************/
    private static void write(ArrayList<Employee> e){
        // Defines variables
        String fileName = "output.txt";

        try{
            // Assume default encoding
            FileWriter fileWriter = new FileWriter(fileName);

            // Always wrap FileWriter in BufferedWriter
            BufferedWriter writer = new BufferedWriter(fileWriter);

            // FOR MANAGER

            // FOR EMPLOYEES
            for (int counter = 0; counter < e.size(); counter++){
                writer.write("Employee " + (counter+1) );
                writer.newLine();
                writer.write("Full Name: " + e.get(counter).getFullName());
                writer.newLine();
                writer.write("Employee ID: " + e.get(counter).getID());
                writer.newLine();
                writer.write("Hourly Wage " + e.get(counter).getHourlyPay());
                writer.newLine();
                writer.write("Number of Hours Worked: " + e.get(counter).getWorkHours());
                writer.newLine();
                writer.write("Total Pay: " + e.get(counter).calc());
                writer.newLine();
            }
            // Closes file
            writer.close();
            System.out.println("\nData Saved!\n");
        }
        catch(IOException ex){
            System.out.println("Error writing to file '" + fileName + "'");
        }
    }
}
