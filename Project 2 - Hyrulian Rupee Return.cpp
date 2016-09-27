/*********************************************
Computer program for the Hyrulian Rupee Return
In this program, the program can convert 
any number of Rupees into exact change 
denoted by particular colors.
Each color has a particular value.

Program made by: Victor Nguyen
*********************************************/

#include <iostream>
using namespace std;

//Function prototypes
void Rupee_return(int);
void displayRupees(int, int, int, int, int, int);

//Define the global integer variables that will be displayed back to the user
//These variables are initialized to 0 by default.
int orange_rupee, purple_rupee, red_rupee, yellow_rupee, blue_rupee, green_rupee;
/***************************************************************
Global variables are appropriate for this program since
only the void Rupee_return function alters the values of these 
variables. The other void function will display these variables.
***************************************************************/
int main()
{
	//Define values for variables that subtract
	int Rupee, orange = 100, purple = 50, red = 20, yellow = 10, blue = 5, green = 1;

	//Asks for user input
	cout << "Please enter the amount of change to dispense: ";
	cin >> Rupee;
	cout << endl << endl;

	//The function call will guide the program to the void function
	Rupee_return(Rupee);

	//Function call will lead to the program to display values
	displayRupees(orange_rupee, purple_rupee, red_rupee, yellow_rupee, blue_rupee, green_rupee);

	//The function will end
	return 0;
}

//Function header
void Rupee_return(int R)
{
	//The while loop function will loop to increase the integer variables
	while (R > 0)
	{
		if (R >= 100)				//The function will begin only when the Rupee count is greater than 100
		{
			R -= 100;				//Subtracts 100 from the total Rupee count
			orange_rupee++;		//Adds one orange rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 100
		}

		else if (R >= 50)			//The function will begin only when the Rupee count is greater than 50
		{
			R -= 50;					//Subtracts 50 from the total Rupee count
			purple_rupee++;		//Adds one purple rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 50
		}
		else if (R >= 20)			//The function will begin only when the Rupee count is greater than 20
		{
			R -= 20;					//Subtracts 20 from the total Rupee count
			red_rupee++;			//Adds one red rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 20
		}
		else if (R >= 10)			//The function will begin only when the Rupee count is greater than 10
		{
			R -= 10;					//Subtracts 10 from the total Rupee count
			yellow_rupee++;		//Adds one yellow rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 10
		}
		else if (R >= 5)			//The function will begin only when the Rupee count is greater than 5
		{
			R -= 5;					//Subtracts 5 from the total Rupee count
			blue_rupee++;			//Adds one blue rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 5
		}
		else if (R >= 1)			//The function will begin only when the Rupee count is greater than 1
		{
			R -= 1;					//Subtracts 1 from the total Rupee count
			green_rupee++;			//Adds one green rupee that was used to make up the inputted Rupee count
			//The function will loop if the Rupee count is still greater than
			//or equal to 1
		}
	}									//The while loop will end once the Rupee count reaches 0
	
}	//Once the void function ends, the program will return back to int main

void displayRupees(int orange_rupee, int purple_rupee, int red_rupee, int yellow_rupee, int blue_rupee, int green_rupee)
{
	//Display back to the user the amount of change
	//The global variables discards the need to redefine new variable names in this function.
	cout << orange_rupee << " Orange Rupee(s)" << endl;
	cout << purple_rupee << " Purple Rupee(s)" << endl;
	cout << red_rupee << " Red Rupee(s)" << endl;
	cout << yellow_rupee << " Yellow Rupee(s)" << endl;
	cout << blue_rupee << " Blue Rupee(s)" << endl;
	cout << green_rupee << " Green Rupee(s)" << endl;
}