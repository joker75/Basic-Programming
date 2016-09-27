/************************************
This program calculates the occupancy 
rate for a hotel.

Program made by:	Victor Nguyen
			vdn140030
			CS 1336.504
************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void Input(double &, double &, double &, int &, double &, double &);
void displayResults(int &, double &, double &);

int main()
{
	//Defines variables
	double floors, rooms, occupied, total_rooms = 0, total_occupied = 0;
	int floor_counter = 0;

	//Function call to get the user input
	Input(floors, rooms, occupied, floor_counter, total_rooms, total_occupied);

	//Function call to display the results
	displayResults(floor_counter, total_rooms, total_occupied);
	return 0;
}

/*******************************************
This function gets the input for the floors, 
the rooms, and the rooms occupied.
*******************************************/
void Input(double &num_floors, double &num_rooms, double &num_occupied, int &counter, double &totalR, double &totalO)
{
	//Gets the number of floors
	cout << "Please enter the number of floors in the hotel: ";
	cin >> num_floors;
	//Validates the number of floors
	while (num_floors < 1)
	{
		cout << "ERROR! Please enter a valid number of floors greater than 1: ";
		cin >> num_floors;
	}

	do
	{
		//Begins with the floor counter at 1, or it increments for the subsequent floors
		++counter;

		//Floor 13 does not exist
		if (counter == 13)
		{
			//If the floor counter is equal to 13, give the following message, and then returns to the top
			cout << "Skipping floor 13.\n";
			continue;
		}

		//Gets the number of rooms 
		cout << "Please enter the number of rooms in the hotel: ";
		cin >> num_rooms;
		//Validates the number of rooms
		while (num_rooms <= 10)
		{
			cout << "ERROR! Please enter a valid number of rooms greater than 10: ";
			cin >> num_rooms;
		}

		//Gets the number of rooms occupied
		cout << "Please enter the number of rooms occupied in the hotel: ";
		cin >> num_occupied;
		cout << endl;
		//Validates the number of rooms occupied
		while (num_rooms < num_occupied)
		{
			cout << "ERROR! Please enter a valid number of rooms occupied with regards to the number of rooms: ";
			cin >> num_occupied;
			cout << endl;
		}

		//Keeps track of the total rooms and the total rooms occupied
		totalR += num_rooms;
		totalO += num_occupied;

	} while (counter < num_floors);	//This part of the do-while loop will restart the loop
}

/********************************************************
This function displays the total number of floors, rooms,
rooms occupied, rooms unoccupied, and the percentage of
rooms occupied.
********************************************************/
void displayResults(int &floors, double &rooms, double &occupied)
{
	cout << "Total floors: " << setw(23) << floors << endl;
	cout << "Total rooms: " << setw(24) << rooms << endl;
	cout << "Total occupied: " << setw(21) << occupied << endl;

	//Calculates the rooms unoccupied, then displays the result
	cout << "Total unoccupied: " << setw(19) << rooms - occupied << endl;

	//Calculates the percentage of rooms occupied with setprecision 
	//to format the output, then displays the result	
	cout << "Percentage of rooms occupied: " << setw(6) << fixed << showpoint
		<< setprecision(2) << occupied / rooms * 100 << "%\n";
}
