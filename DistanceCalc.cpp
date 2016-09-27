/********************************************
This program calculates and displays the rate
in miles per hour as well as kilometers per 
hour. Additionally, this program accepts
input from the user.

Program made by:	Victor Nguyen
					vdn140030
					CS 1337.001
********************************************/
#include <iostream>		// Standard input/output stream

int main()
{
	// Defines variables
	double dist, time, mph;

	// Receive input
	cout << "Please enter a distance: ";
	cin >> dist;

	cout << "Please enter a time: ";
	cin >> time;

	// Calculate rate of miles per hour
	mph = dist / time;
	
	cout << "Miles per hour: " << setprecision(3) << mph << endl
		"Kilometers per hour: " << mph * 1.60934 << endl;

	return 0;
}
