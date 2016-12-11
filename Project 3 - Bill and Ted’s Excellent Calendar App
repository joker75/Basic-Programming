/*********************************************
This program calculates the day of the year in
regards to two different calendar formats:
European and American

Program made by:	Victor Nguyen
					CS 1336.504
					vdn140030
*********************************************/

#include <iostream>
using namespace std;

//Function prototypes
void Input(int &, int &, int &);
int calcDayoftheYear(int, int, bool);
void display(int, int);

/***************************************************
Calls the other functions after validating the date.
***************************************************/
int main()
{
	//Defines variables
	int date1, date2, date3, DayoftheYear;
	bool leap_yr = 0;        //The bool value will come later in the program

	//Gets user input
	Input(date1, date2, date3);

	//Checks for leap years first
	if (date3 % 4 == 0 && !(date3 % 100 == 0))
		leap_yr = 1;
	else if (date3 % 100 == 0 && date3 % 400 == 0)
		leap_yr = 1;
	else
		leap_yr = 0;


	//Validates the date if it's American (MM/DD/YYYY)
	if (date1 >= 1 && date1 <= 12)
	{
		//January - March - May  - July - August  - October - December
		if (date1 == 1 || date1 == 3 || date1 == 5 || date1 == 7 || date1 == 8 || date1 == 10 || date1 == 12)
		{
			if (date2 <= 31)        //(MM/DD/YYYY)
				DayoftheYear = calcDayoftheYear(date1, date2, leap_yr);

			//Invalid dates will cause the program to exit
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}

		//April - June  - September - November
		else if (date1 == 4 || date1 == 6 || date1 == 9 || date1 == 11)
		{
			if (date2 <= 30)                //(MM/DD/YYYY)
				DayoftheYear = calcDayoftheYear(date1, date2, leap_yr);

			//Invalid dates
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}

		//February
		else //date1 == 2
		{
			//Not a leap year
			if (date2 <= 28 && !(leap_yr))        //(MM/DD/YYYY)
				DayoftheYear = calcDayoftheYear(date1, date2, leap_yr);

			//It is a leap year
			else if (date2 <= 29 && leap_yr)//(MM/DD/YYYY)
				DayoftheYear = calcDayoftheYear(date1, date2, leap_yr);

			//Invalid dates
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}


	}

	//Validates the date if it's European (DD/MM/YYYY)
	else if (date1 > 12 && date1 <= 31)
	{
		//January - March - May  - July - August  - October - December
		if (date2 == 1 || date2 == 3 || date2 == 5 || date2 == 7 || date2 == 8 || date2 == 10 || date2 == 12)
		{
			if (date1 <= 31)

				/*******************************************************
				PLEASE NOTE THE SWITCH OF VARIABLES:
				Since European time has date2 as the months,
				there needs to be a switch to accomodate my method
				of calculating the number of days in the American format
				(MM/DD/YYYY)
				*******************************************************/
				DayoftheYear = calcDayoftheYear(date2, date1, leap_yr);
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}

		//April - June  - September - November
		else if (date2 == 4 || date2 == 6 || date2 == 9 || date2 == 11)
		{
			if (date1 <= 30)

				/*******************************************************
				PLEASE NOTE THE SWITCH OF VARIABLES:
				Since European time has date2 as the months,
				there needs to be a switch to accomodate my method
				of calculating the number of days in the American format
				(MM/DD/YYYY)
				*******************************************************/
				DayoftheYear = calcDayoftheYear(date2, date1, leap_yr);
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}

		//February
		else //date2 == 2
		{
			//Not a leap year
			if (date1 <= 28 && !(leap_yr))

				/*******************************************************
				PLEASE NOTE THE SWITCH OF VARIABLES:
				Since European time has date2 as the months,
				there needs to be a switch to accomodate my method
				of calculating the number of days in the American format
				(MM/DD/YYYY)
				*******************************************************/
				DayoftheYear = calcDayoftheYear(date2, date1, leap_yr);

			//It is a leap year
			else if (date1 <= 29 && leap_yr)

				/*******************************************************
				PLEASE NOTE THE SWITCH OF VARIABLES:
				Since European time has date2 as the months,
				there needs to be a switch to accomodate my method
				of calculating the number of days in the American format
				(MM/DD/YYYY)
				*******************************************************/
				DayoftheYear = calcDayoftheYear(date2, date1, leap_yr);

			//Invalid dates
			else
			{
				cout << "ERROR! INVALID DAY! You dun goofed. Program exiting.\n";
				exit(0);
			}
		}
	}

	//Invalid dates if date1 > 31
	else
	{
		cout << "ERROR! INVALID INPUT! You dun goofed. Program exiting.\n";
		exit(0);
	}

	//Function call to validate the format and display the outcome
	display(date1, DayoftheYear);

	return 0;
}

/**************
Gets user input
**************/
void Input(int &digit1, int &digit2, int &digit3)
{
	cout << "Please enter a date separated by slashes: ";
	cin >> digit1;
	cin.ignore();
	cin >> digit2;
	cin.ignore();
	cin >> digit3;
}

/**************************************************************************************
Calculates the day of the year. The days of each month are purposely misplaced.
If the date is December 21st of 1804, the number of days will start with 21, and then
add the number of days of the previous month, in this case, 30 days of November.
Afterwards, the program will fall through all of the cases to add the rest of the days.
**************************************************************************************/
int calcDayoftheYear(int month, int day, bool leap)
{
	//If the inputted year is a leap year
	if (leap)
	{
		switch (month)
		{
		case 12:
			day += 30;	//Days of November
		case 11:
			day += 31;	//Days of October
		case 10:
			day += 30;  //Days of September
		case 9:
			day += 31;  //Days of August
		case 8:
			day += 31;  //Days of July
		case 7:
			day += 30;  //Days of June
		case 6:
			day += 31;  //Days of May
		case 5:
			day += 30;  //Days of April
		case 4:
			day += 31;  //Days of March
		case 3:
			day += 29;  //Days of February (including leap year)
		case 2:
			day += 31;  //Days of January
		}

	}

	//Otherwise, the days of February is changed to 28
	else
	{
		switch (month)
		{

		case 12:
			day += 30;	//Days of November
		case 11:
			day += 31;	//Days of October
		case 10:
			day += 30;  //Days of September
		case 9:
			day += 31;  //Days of August
		case 8:
			day += 31;  //Days of July
		case 7:
			day += 30;  //Days of June
		case 6:
			day += 31;  //Days of May
		case 5:
			day += 30;  //Days of April
		case 4:
			day += 31;  //Days of March
		case 3:
			day += 28;  //Days of February
		case 2:
			day += 31;  //Days of January

		}
	}

	return day;
}

/********************************************
Displays the day of the year after validating
one more time which format the user intended.
********************************************/
void display(int Month_or_Day, int day)
{
	//Validates the date one more time to display proper format with day of the year
	//American format (MM/DD/YYYY)
	if (Month_or_Day >= 1 && Month_or_Day <= 12)
		cout << "That date is day " << day << " of the year according to the American format.\n";

	//Otherwise, it's European
	//European format (DD/MM/YYYY)
	else
		cout << "That date is day " << day << " of the year according to the European format.\n";
}
