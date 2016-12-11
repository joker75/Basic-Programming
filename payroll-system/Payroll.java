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
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
public class payroll {
    // Static scanner object for multiple uses
    private static Scanner input = new Scanner(System.in);

    public static void main(String [] args){
        // Defines variables
        Manager manager = new Manager();
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
            System.out.println("Welcome to the General Payroll System\nIt offers 2 options.\n"
                    + "============================\n"
                    + "1. Document Employee Pay\n"
                    + "2. End the Program.\n"
                    + "Please enter a number to begin.");

            // VALIDATE CHOICES
            try {
                choice = input.nextInt();
                choice = validate(choice);
                input.nextLine();           // Discard current input
            }

            catch(InputMismatchException e){
                System.out.println("Try again. Integers only. ");
                input.nextLine();	// Discard current input
                choice = 0;         // Reset to 0 for new input
            }
            switch (choice){
                case 1:
             		// call input function
                    INPUT(manager);
                    INPUT(workers);

              	    // call the file writing function
                    // INPUT(manager);
                    write(workers, manager);
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

    /**********************************************
    * These functions accept input from the user.
    * Manager Function
    **********************************************/
    private static void INPUT(Manager manager1){
        // Creates a dummy variable to validate input
        String tempS;

        // FULL NAME
        System.out.println("\nPlease enter data for the Manager in charge of "
                            + "these three employees.");
        System.out.print("Full name: ");
        tempS = input.nextLine();
        manager1.setFullName(tempS);

        // ID INPUT VALIDATION
        System.out.print("Please enter an ID (8 integers): ");
        tempS = input.nextLine();
        while(!isNumeric(tempS) || tempS.length() != 8){
            System.out.print("Invalid ID. Please enter an ID with 8 integers: ");
            tempS = input.nextLine();
        }
        manager1.setID(tempS);  // Accepted if valid

        // HOURLY RATE
        System.out.print("Please enter an hourly rate: ");
        tempS = input.nextLine();
        while(!isNumeric(tempS)){
            System.out.print("Invalid rate. Please make sure it is positive. ");
            tempS = input.nextLine();
        }
        manager1.setHourlyPay(Double.parseDouble(tempS));   // Accepted if valid

        // NUMBER OF HOURS
        System.out.print("Please enter the number of REGULAR hours worked: ");
        tempS = input.nextLine();
        while(!isNumeric(tempS) || Double.parseDouble(tempS) > 40){
            System.out.print("Invalid number. Please make sure it is positive "
                    + "and no more than 40 hours. ");
            tempS = input.nextLine();
        }
        manager1.setWorkHours(Double.parseDouble(tempS));   // Accepted if valid

        // OVERTIME HOURLY RATE
        System.out.print("Please enter an OVERTIME hourly rate: ");
        tempS = input.nextLine();
        while(!isNumeric(tempS)){
            System.out.print("Invalid rate. Please make sure it is positive. ");
            tempS = input.nextLine();
        }
        manager1.setOvertimePay(Double.parseDouble(tempS));   // Accepted if valid

        // NUMBER OF OVERTIME HOURS (0-18)
        System.out.print("Please enter the number of OVERTIME hours worked: ");
        tempS = input.nextLine();
        while(!isNumeric(tempS) || Double.parseDouble(tempS) > 18){
            System.out.print("Invalid number. Please make sure it is positive "
                    + "and no more than 18 hours. ");
            tempS = input.nextLine();
        }
        manager1.setOvertimeHours(Double.parseDouble(tempS));   // Accepted if valid

    }

    /**********************************************
     * These functions accept input from the user.
     * Employees Function
     **********************************************/
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
                        + "and no more than 40 hours. ");
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
    private static void write(ArrayList<Employee> e, Manager manager1){
        // Defines variables
        String fileName = "output.txt";

        // Creates calendar and date variables and
        // provides a standard American date format
        Calendar calendar = Calendar.getInstance();
        DateFormat df = new SimpleDateFormat("MM/dd/yy HH:mm:ss");


        try{
            // Always wrap FileWriter in PrintWriter
            PrintWriter writer = new PrintWriter(new FileWriter(fileName, true));

            // Begin by writing the date
            writer.write(df.format(calendar.getTime()));
            writer.println();

            // FOR MANAGER
            writer.write("MANAGER'S Full Name: " + manager1.getFullName());
            writer.println();
            writer.write("Employee ID: " + manager1.getID());
            writer.println();
            writer.write("Hourly Wage " + manager1.getHourlyPay());
            writer.println();
            writer.write("Number of Hours Worked: " + manager1.getWorkHours());
            writer.println();
            writer.write("Regular Pay: " + manager1.calc());
            writer.println();
            writer.write("Overtime Wage " + manager1.getOvertimePay());
            writer.println();
            writer.write("Number of Overtime Hours Worked: " + manager1.getOvertimeHours());
            writer.println();
            writer.write("Overtime Pay: " + manager1.OverTimeCalc());
            writer.println();
            writer.write("Total Pay: " + manager1.totalCalc());
            writer.println();
            writer.println();   // Adds extra lines to the output file

            // FOR EMPLOYEES
            for (int counter = 0; counter < e.size(); counter++){
                writer.write("Employee " + (counter+1) );
                writer.println();
                writer.write("Full Name: " + e.get(counter).getFullName());
                writer.println();
                writer.write("Employee ID: " + e.get(counter).getID());
                writer.println();
                writer.write("Hourly Wage " + e.get(counter).getHourlyPay());
                writer.println();
                writer.write("Number of Hours Worked: " + e.get(counter).getWorkHours());
                writer.println();
                writer.write("Total Pay: " + e.get(counter).calc());
                writer.println();
                writer.println();   // Adds an extra line to the output file
            }
            // Closes file
            writer.close();
            System.out.println("\nData Saved!\nOutput file was not overwritten!\n");
        }
        catch(IOException ex){
            System.out.println("Error writing to file '" + fileName + "'");
        }
    }
}
