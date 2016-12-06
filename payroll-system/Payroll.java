/************************************************
 * This program keeps track of different employee
 * objects for a payroll system. This program can
 * handle:
 * 
 * 
 * Additionally, the user can save the data by
 * writing out to a file. This program can 
 * validate input
 * Program created by: 	Victor Nguyen
 * 						vdn140030
 * 						CS 2336.005 
 ************************************************/

import java.util.*;
public class Payroll {
	// Defines a static variable
	static Scanner input = new Scanner (System.in);
	
	public static void main(String [] args) {
		// Defines variables		
		int choice = 1;			// Allows the user to manipulate the options on the menu
		LinkedList<Person> workers = new LinkedList<Person>();
		
		// MENU DISPLAY
		do{
			System.out.println("Welcome to the General Payroll System\nIt offers 3 options."
					+ "============================\n"
					+ "1. Document Employee Pay\n"
					+ "2. Save Data (Writing to an output file)\n"
					+ "3. End the Program.\n"
					+ "Please enter a number to begin.");
			choice = input.nextInt();
			choice = validate(choice);
			
			/*********************************************
			 * switch (choice){
			 * 	case 1:
			 * 		// call DataCreation to create objects
			 * 		// break;
			 *  case 2:
			 *  	// if (workers.size() == 0)
			 *  	//		System.out.println ("No data have been created! ");
			 *  	// else 
			 *  	// 		call FileWriting to write to a file
			 *  	// break;
			 *  case 3:
			 *  	// End the program
			 *  	// break; 
			 * }
			 *********************************************/
			
			
		}while (choice != 3);
		
		System.out.println("Thank you for using this system!");		
	}
	
	
	/**************************************************
	 * This function validates input with while loops *
	 *************************************************/
	public static int validate(int num){
		while (num < 1 || num > 3){
			System.out.print("INVALID INPUT. Please enter an option listed above (1, 2 or 3): " );
			num = input.nextInt();
		}
		
		// Returns valid menu options
		return num;
	}
	
	/**************************************************
	 * This function validates input with while loops *
	 * Function overloading
	 *************************************************/
	public static String validate(String title){
		while (title != "Employee" || title != "Manager" || title != "Administrator"){
			System.out.print("INVALID INPUT. Please enter a valid title(Employee/Manager/Administrator): " );
			title = input.next();
		}
		
		// Returns valid title
		return title;
	}







}