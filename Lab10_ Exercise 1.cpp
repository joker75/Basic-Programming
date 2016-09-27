/*****************************************
Lab 10 Exercise 1
This program gets the values from the user
and displays them in the reverse order
by using an array.

Program made by:	Victor Nguyen
					vdn140030
					CS 1136.106
*****************************************/
#include <iostream>
using namespace std;

//Function prototypes
void Input(int [] );	//Arrays are automatically passed by reference
void Display(int [] );

int main()
{
	//Defines the array as well as the size
	const int SIZE = 10;
	int num[SIZE];

	//Function call to get the user input
	Input(num);	//Only the variable name is needed to pass the array to another function

	//Function call to display the input in reverse order
	Display(num);	//Only the variable name is needed to pass the array to another function

	return 0;
}

/***********************************
This function gets the user input 
and stores each value into an array.
***********************************/
void Input(int val[])
{
	for (int count = 0; count < 10; ++count)
	{
		cout << "Please enter a value for number " << count + 1 << ": ";
		cin >> val[count];
	}
}

/************************************
This function displays the user input
in reverse order.
************************************/
void Display(int val[])
{
	cout << "\nHere is the input in reverse order:\n\n";

	for (int count = 10; count > 0; --count)
	{
		cout << "The value of number " << count << " is: " << val[count - 1] << endl;
	}
}