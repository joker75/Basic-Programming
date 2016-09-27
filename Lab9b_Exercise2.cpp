/*****************************
Lab 9b Exercise 2
This program reads a file that 
contains a variety of numbers
and displays a percentage of
for negative numbers, numbers
equal to zero, and positive
numbers.

Program made by: Victor Nguyen
*****************************/
#include <iostream>
#include <fstream>	//File reading
#include <string>
#include <iomanip>	//Input/output manipulators
using namespace std;

//Function prototypes
void getInput(double &, double &, double &, double &);
void display(double &, double &, double &, double &);

int main()
{
	//Defines variable counters
	double negative_num = 0, zero_num = 0, positive_num = 0, total = 0;

	//Function call to get the input from the text file
	getInput(negative_num, zero_num, positive_num, total);

	//Function call to display the results
	display(negative_num, zero_num, positive_num, total);

	return 0;
}

/************************************************
This function gets the input from the input file.
The counters are defined here as well.
************************************************/
void getInput(double &neg_counter, double &zero_counter, double &pos_counter, double &total_counter)
{
	//Defines input stream and variables
	ifstream inputFile;
	const string INPUT = "numbers.txt";
	double value;

	inputFile.open(INPUT); //Opens input file 

	//Checks for any values in the input file
	if (inputFile)
	{
		while (inputFile >> value)
		{
			//Keeps track of the total numbers in the text file
			++total_counter;

			//Checks for values and increments the correct category
			if (value < 0)
				++neg_counter;
			else if (value == 0)
				++zero_counter;
			else //(value > 0)
				++pos_counter;
		}

		//Closes the input file
		inputFile.close();
	}

	//inputFile fails
	else
	{
		cout << "No values are present in " << INPUT << ". Program exiting.\n";
		exit(0);
	}
}

/********************************************************
This function calculates and displays the percentages 
of the number of the negative, zero, and positive values.
********************************************************/
void display(double &neg_counter, double &zero_counter, double &pos_counter, double &total_counter)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "There are " << neg_counter / total_counter * 100 << "% negative numbers.\n";
	cout << "There are " << zero_counter / total_counter * 100 << "% numbers that equal zero.\n";
	cout << "There are " << pos_counter / total_counter * 100 << "% positive numbers.\n";

}