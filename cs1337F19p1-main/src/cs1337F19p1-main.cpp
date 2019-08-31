//============================================================================
// Name			: cs1337F19p1-main.cpp
// Author		: Mohammed Ahmed
// Course		: UTDallas CS 1337.502 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		A program that prompts the user for an input file with loan information and an output file.
//      Then it opens the files, calls a function that prints a table to the screen and writes
//      the same to the output file.
//
//		The input file will contain a count of items, and then the items in sets
//		of 3 (int(principal), double(interest rate as decimal), int(monthly payment)).
//
//
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "cs1337F19p1.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::ifstream fileReader;
	std::ofstream fileWriter;
	std::string inputFile;
	std::string outputFile;

//The input file will contain a count of items, and then the items in sets
//		of 3 (int(principal), double(interest rate as decimal), int(monthly payment)).
	cout << "Enter the input file name:  ";
	getline(cin, inputFile);
	cout << endl;

	cout << "Enter the output file name:  ";
	getline(cin, outputFile);
	cout << endl;

	fileReader.open(inputFile.c_str());
	fileWriter.open(outputFile.c_str());

	if (fileReader.is_open() == false)
	{
		cout << "failed to open input file. Exiting..." << endl;
		exit(0);
	}

	if(fileWriter.is_open() == false)
	{
		cout << "Failed to open output file. Exiting..." << endl;
		exit(0);
	}


	int numberOfLoansInFile = -10; // Negative value for debugging if variable does not get changed
	double principal;
	double interest;
	double minimumPayment;

	fileReader >> numberOfLoansInFile;


	for (int i=0; i < numberOfLoansInFile; i++)
	{
		fileReader >> principal;
		fileReader >> interest;
		fileReader >> minimumPayment;

		calculateRepayment(principal, interest, minimumPayment, fileWriter);
	}


	fileReader.close();
	fileWriter.close();

	//Pausing the program for IDE's that would close the console before you can see output
	cout << "Enter something to quit program: ";
	cin.get();

	return 0;
}
