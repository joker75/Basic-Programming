/*****************************************
 * Assignment II: This program calculates the day of
 * the week by receiving the year, the month, and 
 * the day of the month as input. Additionally, it 
 * validates the year, month, and day. Therefore, it 
 * will check for leap years.
 *
 * Created by:	Victor Nguyen on 8/30/2016.
 * 					vdn140030
 *						CS 2336.005
 *						Fall 2016
 *****************************************/
import java.util.InputMismatchException;
import java.util.Scanner;
public class DayOfWeekCalc 
{
	public static void main(String[] args)
	{
		// Defines variables
        Scanner input = new Scanner (System.in);
		int year = 0, month = 0, day = 0;
		boolean leap;	// True for it is a leap year/False for it is not a leap year

		// Input validation & catch bad exceptions
		try
		{
			// Year input
			System.out.print("Please enter a year greater than 0: ");
			year = input.nextInt();
			if (year < 1)
				throw new IllegalArgumentException("No negative years! ");
			leap = check(year);

			// Month input
			System.out.print("Please enter a month (1-12): ");
			month = input.nextInt();
			if (month < 1 || month > 12)
				throw new IllegalArgumentException("Months should not be less than 1 or greater than 12! ");

			// Day input
			System.out.print("Please enter a day (1-31): ");
			day = input.nextInt();

			/*******************************************************
			*The following section validates the days of each month,
			*including February's extra day every leap year.
			*******************************************************/
			//January - March - May  - July - August  - October - December
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
				if (day < 1 || day > 31) {
					throw new IllegalArgumentException("Days should not be less than 1 or greater than 31! ");
				}
			}
			//April - June  - September - November
			else if (month == 4 || month == 6 || month == 9 || month == 11){
				if (day < 1 || day > 30) {
					throw new IllegalArgumentException("Days should not be less than 1 or greater than 30! ");
				}
			}
			//February
			else // month == 2
			{    // It is a leap year
				if ((day < 1 || day > 29) && leap)
					throw new IllegalArgumentException("Days should not be less than 1 or greater than 29! ");
				 // It is not a leap year
				else if ((day < 1 || day > 28) && !leap)
					throw new IllegalArgumentException("Days should not be less than 1 or greater than 28! ");
			}
		}

		// EXCEPTIONS AND END PROGRAM
		catch (IllegalArgumentException ex)
		{
			System.out.println(ex);
			System.exit(0);
		}

		catch (InputMismatchException ex)
		{
			System.out.println(ex + " INVALID INPUT");
			System.exit(0);
		}

		// Calculates the day of the week
		day = calculateDayofWeek (year, month, day);
		
		// Display output and results
		System.out.print ("The day of the week is ");
		switch (day)
		{
			case 0:
				System.out.println("Saturday");
				break;
			case 1:
				System.out.println("Sunday");
				break;
			case 2:
				System.out.println("Monday");
				break;
			case 3:
				System.out.println("Tuesday");
				break;
			case 4:
				System.out.println("Wednesday");
				break;
			case 5:
				System.out.println("Thursday");
				break;
			case 6:
				System.out.println("Friday");
				break;
		}
	}
/***********************************************
This function checks if the year is a leap year.
 **********************************************/
	private static boolean check (int year)
	{
		// Checks for leap years first
		if ( year % 400 == 0)
			return true;			// Yes it is a leap year
		else if ( year % 100 == 0)
			return false;			// No it is not a leap year
		else if ( year % 4 == 0 )
			return true;			// Yes it is a leap year
		else
			return false;			// No it is not a leap year
	}

/********************************************
This function calculates the day of the week.
********************************************/	
	private static int calculateDayofWeek (int y, int m, int dayOfmonth)
	{
		// Switching January and February to the previous year
		if (m <= 2) 	// For January and February assuming valid!
		{
			m +=12; 	// switch to 13 or 14
			y -=1;		// Previous year
		}

		// Calculations
		int century = y / 100;
		int yearOfcentury = y % 100;
		int month_calc = (26 * ( m + 1 ) ) / 10;
		int dayOfweek = dayOfmonth + month_calc + yearOfcentury + (yearOfcentury / 4) + (century / 4) + (5 * century);
		return dayOfweek % 7;
	}
	
}
