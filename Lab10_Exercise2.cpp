/*************************************
Lab 10 Exercise 2
This program tells the user how many
non-negative single digits are entered
into this program.

Program made by:    Victor Nguyen
					vdn140030
					CS 1136
*************************************/
#include <iostream>
using namespace std;

//Function prototypes
void Count_num(int[], int, int);
void Display(const int[], int);

int main()
{
	//Defines the array as well as the size
	const int SIZE = 10;
	int num[SIZE] = {0, 0, 0, 0, 0,
					0, 0, 0, 0, 0 };

	//Defines the variable to get the input
	int value = 0;

	//The while loop keeps getting the user input
	//until the user inputs a 10
	while (value != 10 )
	{
		//Gets user input
		cout << "Enter a one-digit number or 10 to exit: ";
		cin >> value;

		//Checks for invalid input
		while (value < 0 || value > 10)
		{
			cout << "The value " << value << " is invalid.\n";
			cout << "Enter a one-digit number or 10 to exit: ";
			cin >> value;
		}

		//Function call to increment the counter within the array
		Count_num(num, SIZE, value);

		if (value == 10)
			break;
	}

	//Function call to display the results
	Display(num, SIZE);

	return 0;
}

/****************************************************
This function increments the number of times the user
inputted the correct value.
****************************************************/
void Count_num(int storage[], int size, int input)
{
	switch (input)
	{
	case 0:
		++storage[input];
		break;
	case 1:
		++storage[input];
		break;
	case 2:
		++storage[input];
		break;
	case 3:
		++storage[input];
		break;
	case 4:
		++storage[input];
		break;
	case 5:
		++storage[input];
		break;
	case 6:
		++storage[input];
		break;
	case 7:
		++storage[input];
		break;
	case 8:
		++storage[input];
		break;
	case 9:
		++storage[input];
		break;
	}
}

/************************************
This function displays how many times
the user inputted particular values.
************************************/
void Display(const int array[], int size)
{
	for (int counter = 0; counter < size; ++counter)
	{
		if (array[counter] != 0)
			cout << "You entered " << counter << ", " << array[counter] << " time(s).\n";
	}
}