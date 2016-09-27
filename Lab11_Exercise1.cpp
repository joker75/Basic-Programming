/*************************************************
Lab 11 Exercise 1
This program gets the names of the three salesmen,
recieves the sales for each quarter, and displays 
the total amount of sales for each salesmen.

Program made by:	Victor Nguyen
					vdn140030
					CS 1136.106
*************************************************/
#include <iostream>
#include <iomanip>	//Input/output manipulators
#include <string>
using namespace std;

//Function prototypes
void Input(string [], double [][4], int, int);
void Calculate(double[][4], double [], int, int);
void Display(string[], double[], int);

int main()
{
	//Defines the array and size
	const int salesmen = 3;	//Number of salesmen
	const int QTRS = 4;		//Number of quarters for the year
	string names[salesmen];
	double sales[salesmen][QTRS];
	double total[salesmen] = { 0, 0, 0 };

	//Function call to get the input
	Input(names, sales, salesmen, QTRS);

	//Function to call to calculate the total sales
	//3 times, one for each salesmen
	Calculate(sales, total, salesmen, QTRS);

	//Function call to display the total results
	//of each salesmen
	Display(names, total, salesmen);
}

/*********************************************
This function gets the user input of the names
as well as the data for each quarter.
*********************************************/
void Input(string Names[], double money[][4], int num_of_names, int num_of_QTRS)
{
	//Gets name 3 times
	for (int counter = 0; counter < num_of_names; ++counter)
	{
		cout << "Enter in the name for salesman " << counter + 1 << ": ";
		cin >> Names[counter];
		cout << "Now enter in the sales for each quarter for " << Names[counter] << ".\n";

		//Gets sales 4 times
		for (int quarter = 0; quarter < num_of_QTRS; ++quarter)
		{
			cout << "Enter in data for quarter " << quarter + 1 << ": $";
			cin >> money[counter][quarter];
		}
	}
}

/**********************************************************
This function  calculates the total sales for each salesmen
in a 2D array named total.
**********************************************************/
void Calculate(double money[][4], double total[], int num_of_names, int num_of_QTRS)
{
	for (int row = 0; row < num_of_names; ++row)
		for (int column = 0; column < num_of_QTRS; ++column)
			total[row] += money[row][column];
}

/*****************************************
This function displays the total sales for
each of the salesmen. The string array is
needed to display the names as well.
*****************************************/
void Display(string Names[], double total[], int num_of_names)
{
	//Formats the output
	cout << fixed << showpoint << setprecision(2);

	//Displays the output
	for (int counter = 0; counter < num_of_names; ++counter)
		cout << "Total sales for " << Names[counter] << " is $" << total[counter] << endl;
}
