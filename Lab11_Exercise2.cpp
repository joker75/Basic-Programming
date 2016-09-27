/*************************************************
Lab 11 Exercise 2
This program gets the names of the three salesmen,
recieves the sales for each quarter, and displays
the highest sales for each quarter.

Program made by:	Victor Nguyen
					vdn140030
					CS 1136.106
*************************************************/
#include <iostream>
#include <iomanip>	//Input/output manipulators
#include <string>
using namespace std;

//Function prototypes
void Input(string[], double[3][4]);
void Display(const string[], double[3][4], int &, int &);

int main()
{
	//Defines the array and size
	const int salesmen = 3;	//Number of salesmen
	const int QTRS = 4;		//Number of quarters for the year
	string names[salesmen];
	double sales[salesmen][QTRS];

	//Initialize the location counters for the highest of each quarter
	int Name = 0;
	int Quarter = 0;

	//Function call to get the input
	Input(names, sales);
	
	//Function call to display the highest sales four times
	for (int counter = 0; counter < QTRS; ++counter, ++Name, ++Quarter)
		Display(names, sales, Name, Quarter);
}

/*********************************************
This function gets the user input of the names
as well as the data for each quarter.
*********************************************/
void Input(string Names[], double money[3][4])
{
	//Gets name 3 times
	for (int counter = 0; counter < 3; ++counter)
	{
		cout << "Enter in the name for salesman " << counter + 1 << ": ";
		cin >> Names[counter];
		cout << "Now enter in the sales for each quarter for " << Names[counter] << ".\n";
		
		//Gets sales for each quarter
		for (int quarter = 0; quarter < 4; ++quarter)
		{
			cout << "Enter in data for quarter " << quarter + 1 << ": $";
			cin >> money[counter][quarter];
		}
	}
}

/*****************************************
This function displays the highest sales 
for each of the quarter. The string array 
is needed to display the names as well.
*****************************************/
void Display(const string Namearray[3], double SalesArr[3][4], int &Namecounter, int &QuarterCounter)
{
	//Initializes the highest sales as the first value
	double HighestQuarter = SalesArr[0][0];

	//Runs through the quarters 4 times to search for
	//the highest sales
	for (int counter = 0; counter < 4; counter++)
	{
		//If the sales is higher than the previous highest
		if (SalesArr[counter][QuarterCounter] > HighestQuarter)
		{
			//Sets that sales as the highest
			HighestQuarter = SalesArr[counter][QuarterCounter];

			//Keep the counter as the namecount/ the person/ row number
			Namecounter = counter;
		}
	}

	//Outputs the person name, quarter number, and sales amount
	//with the formatted output
	cout << "Salesperson " << Namearray[Namecounter] << " had the highest sales for Quarter " << QuarterCounter + 1 << " with $"
		<< fixed << setprecision(2) << HighestQuarter << endl;

}