/********************************
Lab 10 Exercise 3
This program gets the user input
of names and displays to the user 
of those names with an array.

Program made by:	Victor Nguyen
					vdn140030
					CS 1136
********************************/
#include <iostream>
#include <string>
using namespace std;

//Function prototypes
int Input(string[], int);
void Display(const string[], int);

int main()
{
	//Initializes the array size
	const int SIZE = 10;
	string names[SIZE];

	//Initializes the variable num_of_names
	int num_of_names = Input(names, SIZE);

	//Function call to the Display function
	Display(names, num_of_names);

	return 0;
}

/*****************************************
This function gets the user input of names
*****************************************/
int Input(string inputnames[], int size)
{
	//Initializes the counter variable that will be
	//returned back to int main
	int counter = 0;

	//This for loop will ask for 8 names
	//10 total elements - 2 = 8 names
	for (; counter < size - 2; ++counter)
	{
		cout << "Enter in name " << counter + 1 << ": ";
		cin >> inputnames[counter];
	}

	//The value returned should be 8
	return counter;
}

/***********************************************
This function displays the names from the user.
The variable named number tells the for loop how
many times will it read out of the string array.
***********************************************/
void Display(const string names[], int number)
{
	for (int counter = 0; counter < number; ++counter)
		cout << "Name " << counter + 1 << " is " << names[counter] << endl;
}