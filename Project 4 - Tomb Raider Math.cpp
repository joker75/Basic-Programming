/********************************************
Project 4 - Tomb Raider Math
This program reads in Roman numerals
from an input file, calculates the final sum,
and outputs the answer in Roman numeral form
for an output file.

Program made by:	Victor Nguyen
vdn140030
CS 1336.504
********************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function prototypes
int RomantoValue(string);
int ReturnValue(char);
string ValuetoRoman(int);

int main()
{
	//Defines variables
	int total = 0;
	char op;

	//These strings get the Roman numerals 
	//before and after the operator
	string RomanNumerals1 = "", RomanNumerals2 = "";

	ifstream input("input.txt");
	ofstream output("output.txt");

	//First checks if the input file can open
	if (input)
	{
		//Afterwards, the program can get the input 
		//from the input file one line at a time
		while (input)
		{
			//Reads in the first set of Roman characters
			input >> RomanNumerals1;

			//Function call to convert Roman numerals to values
			int value1 = RomantoValue(RomanNumerals1);

			//Skips the space
			input.ignore();

			//Reads in operator
			input >> op;

			//Skips the next space
			input.ignore();

			//Reads in the next set of Roman characters
			input >> RomanNumerals2;

			//Converts the next set of Roman characters
			int value2 = RomantoValue(RomanNumerals2);

			//Uses the operator to either add or subtract
			if (op == '+')
				total = value1 + value2;
			else //op == '-')
				total = value1 - value2;

			//Converts the total value back to Roman characters
			string Answer = ValuetoRoman(total);

			//Writes the answer in Roman characters to an output file
			output << Answer << endl;

			//Skips the endline
			input.ignore();
		}
	}

	else //If opening input file fails
		cout << "ERROR!! There's no available input file!\nPlease try again.\n";

	//Closes both files
	input.close();
	output.close();

	return 0;
}

/******************************************************
This function compares the values of the Roman numerals
by looking at the first two characters and calling
another function to obtain specific values.
The subtraction of values applies only for
Roman numerals that are out of order.
******************************************************/
int RomantoValue(string Roman)
{
	//Defines variables
	int convertedValue = 0;

	for (int counter = 0; counter < Roman.length() - 1; ++counter)
	{
		//If the Roman numerals are out of order
		if (ReturnValue(Roman.at(counter)) < ReturnValue(Roman.at(counter + 1)))
			convertedValue -= ReturnValue(Roman.at(counter));

		//Otherwise, the values will be added as normal
		else
			convertedValue += ReturnValue(Roman.at(counter));

		//This will make sure that the value of the
		//last character of the string is added as well
		if (counter == Roman.length() - 2)
			convertedValue += ReturnValue(Roman.at(counter + 1));
	}

	//These if statements will check for single
	//Roman character strings
	if (Roman.length() == 1)
	{
		if (Roman == "I")
			convertedValue += 1;
		else if (Roman == "V")
			convertedValue += 5;
		else if (Roman == "X")
			convertedValue += 10;
		else if (Roman == "L")
			convertedValue += 50;
		else if (Roman == "C")
			convertedValue += 100;
	}

	//Returns a value back to int main
	return convertedValue;
}

/*************************************
This function returns a specific value
based on the Roman character.
*************************************/
int ReturnValue(char RomanChar)
{
	if (RomanChar == 'I')
		return 1;
	else if (RomanChar == 'V')
		return 5;
	else if (RomanChar == 'X')
		return 10;
	else if (RomanChar == 'L')
		return 50;
	else //(RomanChar == 'C')
		return 100;
}

/*******************************************
This function converts the converted integer
value from the input file back to a single
Roman character string.
*******************************************/
string ValuetoRoman(int total)
{
	
	switch (total)
	{
		case 1:
			return "I";
		case 2:
			return "II";
		case 3:
			return "III";
		case 4:
			return "IV";
		case 5:
			return "V";
		case 6:
			return "VI";
		case 7:
			return "VII";
		case 8:
			return "VIII";
		case 9:
			return "IX";
		case 10:
			return "X";
		case 11:
			return "XI";
		case 12:
			return "XII";
		case 13:
			return "XIII";
		case 14:
			return "XIV";
		case 15:
			return "XV";
		case 16: 
			return "XVI";
		case 17: 
			return "XVII";
		case 18: 
			return "XVIII";
		case 19: 
			return "XIX";
		case 20: 
			return "XX";
		case 21: 
			return "XXI";
		case 22: 
			return "XXII";
		case 23: 
			return "XXIII";
		case 24: 
			return "XXIV";
		case 25: 
			return "XXV";
		case 26: 
			return "XXVI";
		case 27: 
			return "XXVII";
		case 28: 
			return "XXVIII";
		case 29: 
			return "XXIX";
		case 30: 
			return "XXX";
		case 31: 
			return "XXXI";
		case 32: 
			return "XXXII";
		case 33: 
			return "XXXIII";
		case 34: 
			return "XXXIV";
		case 35: 
			return "XXXV";
		case 36: 
			return "XXXVI";
		case 37: 
			return "XXXVII";
		case 38: 
			return "XXXVIII";
		case 39: 
			return "XXXIX";
		case 40: 
			return "XL";
		case 41: 
			return "XLI";
		case 42: 
			return "XLII";
		case 43: 
			return "XLIII";
		case 44: 
			return "XLIV";
		case 45: 
			return "XLV";
		case 46: 
			return "XLVI";
		case 47: 
			return "XLVII";
		case 48: 
			return "XLVIII";
		case 49: 
			return "XLIX";
		case 50: 
			return "L";
		case 51: 
			return "LI";
		case 52: 
			return "LII";
		case 53: 
			return "LIII";
		case 54: 
			return "LIV";
		case 55: 
			return "LV";
		case 56: 
			return "LVI";
		case 57: 
			return "LVII";
		case 58: 
			return "LVIII";
		case 59: 
			return "LIX";
		case 60: 
			return "LX";
		case 61: 
			return "LXI";
		case 62: 
			return "LXII";
		case 63: 
			return "LXIII";
		case 64: 
			return "LXIV";
		case 65: 
			return "LXV";
		case 66: 
			return "LXVI";
		case 67: 
			return "LXVII";
		case 68: 
			return "LXVIII";
		case 69: 
			return "LXIX";
		case 70: 
			return "LXX";
		case 71: 
			return "LXXI";
		case 72: 
			return "LXXII";
		case 73: 
			return "LXXIII";
		case 74: 
			return "LXXIV";
		case 75: 
			return "LXXV";
		case 76: 
			return "LXXVI";
		case 77: 
			return "LXXVII";
		case 78: 
			return "LXXVIII";
		case 79: 
			return "LXXIX";
		case 80: 
			return "LXXX";
		case 81: 
			return "LXXXI";
		case 82: 
			return "LXXXII";
		case 83: 
			return "LXXXIII";
		case 84: 
			return "LXXXIV";
		case 85: 
			return "LXXXV";
		case 86: 
			return "LXXXVI";
		case 87: 
			return "LXXXVII";
		case 88: 
			return "LXXXVIII";
		case 89: 
			return "LXXXIX";
		case 90: 
			return "XC";
		case 91: 
			return "XCI";
		case 92: 
			return "XCII";
		case 93: 
			return "XCIII";
		case 94: 
			return "XCIV";
		case 95: 
			return "XCV";
		case 96: 
			return "XCVI";
		case 97: 
			return "XCVII";
		case 98: 
			return "XCVIII";
		case 99: 
			return "XCIX";
		case 100: 
			return "C";
		case 101: 
			return "CI";
		case 102: 
			return "CII";
		case 103: 
			return "CIII";
		case 104: 
			return "CIV";
		case 105: 
			return "CV";
		case 106: 
			return "CVI";
		case 107: 
			return "CVII";
		case 108: 
			return "CVIII";
		case 109: 
			return "CIX";
		case 110: 
			return "CX";
		case 111: 
			return "CXI";
		case 112: 
			return "CXII";
		case 113: 
			return "CXIII";
		case 114: 
			return "CXIV";
		case 115: 
			return "CXV";
		case 116: 
			return "CXVI";
		case 117: 
			return "CXVII";
		case 118: 
			return "CXVIII";
		case 119: 
			return "CXIX";
		case 120: 
			return "CXX";
		case 121: 
			return "CXXI";
		case 122: 
			return "CXXII";
		case 123: 
			return "CXXIII";
		case 124: 
			return "CXXIV";
		case 125: 
			return "CXXV";
		case 126: 
			return "CXXVI";
		case 127: 
			return "CXXVII";
		case 128: 
			return "CXXVIII";
		case 129: 
			return "CXXIX";
		case 130: 
			return "CXXX";
		case 131: 
			return "CXXXI";
		case 132: 
			return "CXXXII";
		case 133: 
			return "CXXXIII";
		case 134: 
			return "CXXXIV";
		case 135: 
			return "CXXXV";
		case 136: 
			return "CXXXVI";
		case 137: 
			return "CXXXVII";
		case 138: 
			return "CXXXVIII";
		case 139: 
			return "CXXXIX";
		case 140: 
			return "CXL";
		case 141: 
			return "CXLI";
		case 142: 
			return "CXLII";
		case 143: 
			return "CXLIII";
		case 144: 
			return "CXLIV";
		case 145: 
			return "CXLV";
		case 146: 
			return "CXLVI";
		case 147: 
			return "CXLVII";
		case 148: 
			return "CXLVIII";
		case 149: 
			return "CXLIX";
		case 150: 
			return "CL";
		case 151: 
			return "CLI";
		case 152: 
			return "CLII";
		case 153: 
			return "CLIII";
		case 154: 
			return "CLIV";
		case 155: 
			return "CLV";
		case 156: 
			return "CLVI";
		case 157: 
			return "CLVII";
		case 158: 
			return "CLVIII";
		case 159: 
			return "CLIX";
		case 160: 
			return "CLX";
		case 161: 
			return "CLXI";
		case 162: 
			return "CLXII";
		case 163: 
			return "CLXIII";
		case 164: 
			return "CLXIV";
		case 165: 
			return "CLXV";
		case 166: 
			return "CLXVI";
		case 167: 
			return "CLXVII";
		case 168: 
			return "CLXVIII";
		case 169: 
			return "CLXIX";
		case 170: 
			return "CLXX";
		case 171: 
			return "CLXXI";
		case 172: 
			return "CLXXII";
		case 173: 
			return "CLXXIII";
		case 174: 
			return "CLXXIV";
		case 175: 
			return "CLXXV";
		case 176: 
			return "CLXXVI";
		case 177: 
			return "CLXXVII";
		case 178: 
			return "CLXXVIII";
		case 179: 
			return "CLXXIX";
		case 180: 
			return "CLXXX";
		case 181: 
			return "CLXXXI";
		case 182: 
			return "CLXXXII";
		case 183: 
			return "CLXXXIII";
		case 184: 
			return "CLXXXIV";
		case 185: 
			return "CLXXXV";
		case 186: 
			return "CLXXXVI";
		case 187: 
			return "CLXXXVII";
		case 188: 
			return "CLXXXVIII";
		case 189: 
			return "CLXXXIX";
		case 190: 
			return "CXC";
		case 191: 
			return "CXCI";
		case 192:
			return "CXCII";
		case 193:
			return "CXCIII";
		case 194:
			return "CXCIV";
		case 195:
			return "CXCV";
		case 196:
			return "CXCVI";
		case 197:
			return "CXCVII";
		case 198:
			return "CXCVIII";
		case 199:
			return "CXCIX";
		case 200:
			return "CC";
	}
}