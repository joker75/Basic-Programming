/***********************************************************
This program can translate a number from integer format to
month-day format. This program involves a class and a static
string variable. Additionally, input validation is included.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1337.001
***********************************************************/
#include<iostream>
#include<string>
using namespace std;

// Class declaration
class DayOfYear
{
// Access specifier
public:
    // Defines variables
    int day;
    static string Month;     // Static member variable of type string

    // Constructor function
    DayOfYear(int input)
    {
        // Defines variable
        day = input;

        if(day >= 1 && day <= 31)
            Month = "January ";

        else if(day >= 32 && day <= 59)
        {
            Month = "February ";
            day -= 31;
        }
        else if(day >= 60 && day <= 90)
        {
            Month = "March ";
            day -= 59;
        }
        else if(day >= 91 && day <= 120)
        {
            Month = "April ";
            day -= 90;
        }
        else if(day >= 121 && day <= 151)
        {
            Month = "May ";
            day -= 120;
        }
        else if(day >= 152 && day <= 181)
        {
            Month = "June ";
            day -= 151;
        }
        else if (day >= 182 && day <= 212)
        {
            Month = "July ";
            day -= 181;
        }
        else if(day >= 213 && day <= 243)
        {
            Month = "August ";
            day -= 212;
        }
        else if(day >= 244 && day <= 273)
        {
            Month = "September ";
            day -= 243;
        }
        else if(day >= 274 && day <= 304)
        {
            Month = "October ";
            day -= 273;
        }
        else if(day >= 305 && day <= 334)
        {
            Month = "November ";
            day -= 304;
        }
        else // (day >= 335 && day <= 365)
        {
            Month = "December ";
            day -= 334;
        }
    } // End of constructor function

	// Print function
	void print()
    {
        cout << Month << day << endl;
    } // End of print function

}; // End Class DayOfYear

// Function prototype
int getsInput();

// Definition of static member variable Month
string DayOfYear::Month = "";

int main()
{
	// Defines variable and gets input
	int input = getsInput();

    // Figure out the date
    DayOfYear date(input);

    // Beginning statement for results
    cout << "Day " << input << " is ";

    // Prints results
    date.print();

	//system("pause");
	return 0;
}

/********************************************
This function gets the input along with input
validation.
********************************************/
int getsInput()
{
    // Defines variable
	int num;
	cout << "Please enter a number from 1 to 365" << endl;
    cin >> num;

	// Input validation
    while (num < 1 || num > 365) 	// if invalid, repeat this while loop
	{
		cout << "INVALID DAY." << endl;
		cout << "Please enter a number from 1 to 365" << endl;
		cin >> num;
	}

	// Return the validated input
	return num;
}
