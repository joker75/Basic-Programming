/*
/*****************************************
 * Assignment VIII: This project can
 * store rankings and names of text
 * files into arrays of maps. Next,
 * the program will prompt the user
 * to input a year, gender, and name.
 *
 * Created by:  Victor Nguyen on 11/1/2016.
 *              vdn140030
 *				CS 2336.005
 *				Fall 2016
 *****************************************/
import java.util.*;
public class BabyNameRanking {
    public static void main(String [] args ){
		@SuppressWarnings("resource")

		// Defines variables
		Scanner iUser = new Scanner (System.in);
        int yr = 0;							// Year
        char gen = 'a';						// Gender
        String name = null;					// Baby name
		char inquiry;						// Prompts the user for another response
		fileReader r = new fileReader();	// Call the fileReader constructor

		ArrayList<Map<String, Integer>> boyRanks = new ArrayList<>(); 	// String is the name = key
		ArrayList<Map<String, Integer>> girlRanks = new ArrayList<>();	// Integer is the ranking #

		/*
		********
		0 = 2006
		1 = 2007
		2 = 2008
		3 = 2009
		4 = 2010
		5 = 2011
		6 = 2012
		7 = 2013
		8 = 2014
		9 = 2015
		*******/
		// Store into the ArrayList of maps
		// 10 maps, 1000 rankings EACH
		for (int i = 0; i < 10; i++){
			r.openFile(i);
			r.readFile(boyRanks, girlRanks);
			r.closeFile();
		}		
		
		// NOTE: Consider a general input validation function that verifies the year and gender...		
		do{
			try{
				// YEAR INPUT
				System.out.print("Please enter a year: ");
				yr = iUser.nextInt();
				// Input validation loop
				while (yr < 2006 || yr > 2015){
					System.out.print("Error. Please enter a valid year between 2006 and 2015: ");
					yr = iUser.nextInt();
				}

				// GENDER INPUT
				System.out.print("Please enter a gender: ");
				gen = iUser.next().charAt(0);
				// Input validation loop
				while (gen != 'm' && gen != 'M' && gen != 'f' && gen != 'F'){
					System.out.print("Error. Please enter a gender (M/F): ");
					gen = iUser.next().charAt(0);
				}

				// NAME INPUT
				System.out.print("Please enter a name: ");
				name = iUser.next();
			}
			catch (InputMismatchException ex){
				System.out.println("INPUT ERROR! ");
			}

			// Receive stuff here
			// Use the same if statement condition to check the ranking in the
			// ArrayList by utilizing the name as the KEY
			if ((gen == 'm' || gen == 'M') && ((boyRanks.get(yr - 2006)).containsKey(name)))		// Set up another condition if the rank EXISTS
				System.out.println("Boy name " + name + " is ranked #" + ((boyRanks.get(yr - 2006)).get(name)) + " in year " + yr);
			else if ((gen == 'f' || gen == 'F')	&& ((girlRanks.get(yr - 2006)).containsKey(name)))	// Set up another condition if the rank EXISTS
				System.out.println("Girl name " + name + " is ranked #" + ((girlRanks.get(yr - 2006)).get(name)) + " in year " + yr);
			else
				System.out.println("Name " + name + " is not found.");

			// Query the user for another entry
			System.out.print("Would you like to enter another inquiry? (Y/N) ");
			inquiry = iUser.next().charAt(0);

			// Input validation
			while (inquiry != 'Y' && inquiry != 'y' && inquiry != 'N' && inquiry != 'n')
			{
				System.out.print("Would you like to enter another inquiry? (Y/N) ");
				inquiry = iUser.next().charAt(0);
			}

		// This condition will repeat the loop
		}while(inquiry == 'Y' || inquiry == 'y');

		// End program
		System.out.println("Thank you for using this program!\n");
    }
}
