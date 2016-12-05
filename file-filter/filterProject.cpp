/********************************************************
This program can read an input file, create another copy, 
perform an encryption, and transform it to all uppercase.

Program made by:	Victor Nguyen
					vdn140030
					CS 1337.001
*******************************************************/
#include <iostream>
#include <fstream>	// Reading and writing to files
#include <cctype>	// Changing all letters to uppercase
using namespace std;

// Defines an abstract class
class FileFilter
{
	//Access Specifier
public:	

	// Defines pure virtual functions
	virtual void doFilter(ifstream &in, ofstream &out) = 0;
	virtual char transform(char ch) = 0;
};

// Defines a copy filter class
class copyFilter : public FileFilter
{

	// Since this private function is a copy,
	// the function will just return its input
	char transform(char ch)
	{
		return ch;
	}

	// Access Specifier
public:
	void doFilter(ifstream &in, ofstream &out)
	{
		in.clear();
		in.seekg(0);				// Resets the file reader to the beginning
		char c;						// Defines the character variable for transformation
		char end;					// This character will "peek" for the end of file
		cout << "Performing a copy filter...\n";
		while (in)					// File input loop
		{
			end = in.peek();		// Peek for the end of the file
			if (end == EOF)			// Break if it's at the end of the file
				break;
			in.get(c);
			c = transform(c);
			out << c;
		}
	}
};

// Defines a uppercase filter class
class upperFilter : public FileFilter
{

// This private function will uppercase all letters
	char transform(char ch)
	{
		return toupper(ch);
	}

	// Access Specifier
public:
	void doFilter(ifstream &in, ofstream &out)
	{
		in.clear();
		in.seekg(0);				// Resets the file reader to the beginning
		char c;						// Defines the character variable for transformation
		char end;					// This character will "peek" for the end of file
		cout << "Performing an uppercase filter...\n";
		while (in)					// File input loop
		{
			end = in.peek();		// Peek for the end of the file
			if (end == EOF)			// Break if it's at the end of the file
				break;
			in.get(c);
			c = transform(c);
			out << c;
		}
	}
};

// Defines an encryption filter class
class encryptFilter : public FileFilter
{
	// Anonymous union will contain the encryption key
	union {
		int code;
		char data[4];		// Let's use this another day
	}key; 
	
	// This private function will encrypt all the letters
	char transform(char ch)
	{
		// Defines variable
		static int counter = 0;											// Static counter for multiple function calls
																				// that come from the while loop
		int charAsNum = static_cast <int> (ch) + key.code;	// Converts the characters to integers
		counter++;															// Increments to the next value
		counter %= 4;														// Keeps the counter from 0-3
		return static_cast <char> (charAsNum % 256);		// Convers number back to a character
																				// Prevents characters from going
																				// past 256
	}

	// Access Specifier
public:
	encryptFilter(int val)						// Constructor will take an integer as an argument
	{
		key.code = val;
	}
	void doFilter(ifstream &in, ofstream &out)
	{
		in.clear();
		in.seekg(0);				// Resets the file reader to the beginning
		char c;						// Defines the character variable for transformation
		char end;					// This character will "peek" for the end of file
		cout << "Performing an ecryption filter...\n";
		while (in)					// File input loop
		{
			end = in.peek();		// Peek for the end of the file
			if (end == EOF)			// Break if it's at the end of the file
				break;
			in.get(c);
			c = transform(c);
			out << c;
		}
	}
};

int main()
{
	//Defines the input and output files
	ifstream iFile("filterProjectInput.txt");
	ofstream UPPER("filterProjectToUpper.txt"), encryption ("filterProjectEncrypt.txt"), copy ("filterProjectCopied.txt");
	int value = 5;		// Encryption key

	// If the input file does not exist, display an error message
	if (!iFile)
		cout << "ERROR!! There's no available input file!\nPlease try again.\n";
	else
	{
		// Defines class objects
		FileFilter *p = &copyFilter();
		p->doFilter(iFile, copy);

		p = &upperFilter();
		p->doFilter(iFile, UPPER);

		cout << "The encryption value is " << value << endl;
		p = &encryptFilter(value);
		p->doFilter(iFile, encryption);
	}

	//Closes all files
	iFile.close();
	UPPER.close();
	encryption.close();
	copy.close();
	system("pause");
	return 0;
}
