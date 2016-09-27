/******************************************************
This program converts the number of work hours to days.
This program can use classes.

Program made by:    Victor Nguyen
                    vdn140030
                    CS 1337.001
******************************************************/
#include <iostream>
#include <iomanip>  // Manipulates input and output
#include "NUMDAYS.h"
using namespace std;

// This setter function sets the value of a for hours
void NumDays::setHours(int a)
    {hours=a;}

// This function overloads the + operator
int NumDays::operator +(NumDays & right)
{
    return hours+right.hours;       // Returns the sum
}

// This function overloads the - operator
int NumDays::operator -(NumDays & right)
{
    return hours-right.hours;       // Returns the difference
}

// This function overloads the ++ operator
int NumDays::operator ++(int)
{
    int incr=hours;
    hours++;
    day=hours/8.0;
    return incr;
}

// This function overloads the ++ operator
int NumDays::operator ++()
{
    hours++;
    day=hours/8.0;
    return hours;
}

// This function overloads the -- operator
int NumDays::operator --(int)
{
    int decr=hours;
    hours--;
    day=hours/8.0;
    return decr;
}

// This function overloads the -- operator
int NumDays::operator --()
{
    hours--;
    day=hours/8.0;
    return hours;
}

int main()
{
    // Defines objects of class NumDays with initialized values
    NumDays employee1 (18);
    NumDays employee2 (12);

    // Manipulate output
    // Basic results
    cout << setprecision(2) << fixed << showpoint;
    cout << "Employee 1: " << employee1.getHour() << " hours or "
        << employee1.getDay() << " days" << endl;
    cout << "Employee 2: " << employee2.getHour() << " hours or "
        << employee2.getDay() << " days" << endl << endl;

    // + and - operators
    cout << "Employee 1 + 2: " << employee1 + employee2 << " hours" << endl;
    cout << "Employee 1 - 2: " << employee1 - employee2 << " hours" << endl;

    // Prefix operators
    // ++ (Increment) Operator
    ++employee1;
    ++employee2;
    cout << "\nPrefix Operators:\n";
    cout << "++Employee 1: " << employee1.getHour() << " hours or "
        << employee1.getDay() << " days" << endl;
    cout << "++Employee 2: " << employee2.getHour() << " hours or "
        << employee2.getDay() << " days" << endl;

    // -- (Decrement) Operator
    --employee1;
    --employee2;
    cout << "--Employee 1: " << employee1.getHour() << " hours or "
        << employee1.getDay() << " days" << endl;
    cout << "--Employee 2: " << employee2.getHour() << " hours or "
        << employee2.getDay() << " days" << endl;

    // Postfix operators
    // ++ (Increment) Operator
    employee1++;
    employee2++;
    cout << "\nPostfix Operators:\n";
    cout << "Employee 1++: " << employee1.getHour() << " hours or "
        << employee1.getDay() << " days" << endl;
    cout << "Employee 2++: " << employee2.getHour() << " hours or "
        << employee2.getDay() << " days" << endl;

    // -- (Decrement) Operator
    employee1--;
    employee2--;
    cout << "Employee 1--: " << employee1.getHour() << " hours or "
        << employee1.getDay() << " days" << endl;
    cout << "Employee 2--: " << employee2.getHour() << " hours or "
        << employee2.getDay() << " days" << endl;
    // system ("pause");
    return 0;
}
