/*********************************************
Project 5 - Tie Fighter Patrols
This program gets the name and coordinates 
from an input file, calculates the area from
the data given, and writes the result with the
pilot name to the output file.

Program made by:	Victor Nguyen
					vdn140030
					CS 1336.504
*********************************************/
#include <iostream>
#include <iomanip>	//Input/output manipulators
#include <string>	//Names will be read as strings
#include <fstream>	//Reading from and writing to files 
#include <cmath>	//Absolute value
using namespace std;


//Defines specific sizes for both x and y coordinates of an array
const int ROWS = 15;//Rows for 15 pairs of coordinates
const int COLS = 2;	//Columns for either x or y

//Function prototypes
void Getsinput(ifstream &, double[ROWS][COLS]);	//Second bracket MUST be initialized
double Calc(double[ROWS][COLS]);
void Display(ofstream &, string, double);

int main()
{
	//Defines the input and output files
	ifstream input("pilot_routes.txt");
	ofstream output("pilot_areas.txt");

	//Defines variables and array
	string name;
	double X_Y[ROWS][COLS];

	//First checks if the input file can open
	if (input)
		while (input)
		{
			//Initializes/returns all of the coordinates to 0 
			//just in case more data is present in the file
			for (int x = 0; x < ROWS; ++x)
				for (int y = 0; y < COLS; ++y)
					X_Y[x][y] = 0;

			//Reads in the name
			input >> name;

			//Function call to read in the coordinates
			//for the array
			Getsinput(input, X_Y);

			//Function call to calculate the area
			double answer = Calc(X_Y);

			//Function call to display the results
			Display(output, name, answer);

			//Skips the end line
			input.ignore();
			
		}

	//If opening input file fails
	else 
		cout << "ERROR!! There's no available input file!\nPlease try again.\n";

	//Closes both files once there's no more input to be read
	input.close();
	output.close();

	return 0;
}

/************************************************
This function gets the input from the input file.
The array holds the coordinates.
************************************************/
void Getsinput(ifstream &inputfile, double array[ROWS][COLS])
{

	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			inputfile.ignore();		//Skips the comma/single space
			inputfile >> array[i][j];	//Reads data
		}

		//for loop breaks only if the '\n' is 
		//used after the last coordinate
		if (inputfile.peek() == '\n')
			break;
	}

}

/************************************************
This function calculates the area 
by multiplying the sum of pairs of x values with
the difference of pairs of y values.
This process is repeated as many times as needed.
************************************************/
double Calc(double array[ROWS][COLS])
{
	//Defines the summation variable
	double sum = 0;

	//This for loop calculates the sum
	for (int counter = 0; counter <= ROWS - 2; ++counter)
		sum += ((array[counter][0] + array[counter + 1][0]) * (array[counter + 1][1] - array[counter][1]));

	//Sum changes to the absolute value of the summation multiplied by one-half
	return abs(sum) * 0.5;
}

/********************************
This function writes the results
as well as the name to the output
file.
********************************/
void Display(ofstream &outputfile, string pilot, double area)
{
	//Writes to the output file with a formtted output
	outputfile << pilot << "\t" << fixed << showpoint << setprecision(2) << area << endl;
}