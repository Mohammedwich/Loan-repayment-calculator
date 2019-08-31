//============================================================================
// Name			: cs1337F19p1-amortize.cpp
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
#include <iomanip>
#include <math.h>

#include "cs1337F19p1.h"

using std::cout;
using std::cin;
using std::endl;



// Penny fractions are rounded in such a way to make it so they do not count. They are not required to be paid.
void calculateRepayment(double principal, double interest, double minimumPayment, std::ofstream & writer)
{
	double monthlyInterestRate = interest / 12;	// monthly rate of APR
	int paymentsMade = 0;	//Counter to track number of payments made
	double interestPaid = 0;	//Interest accumulator

	// Loan details
	cout << "Starting balance: $" << std::fixed << std::setprecision(2) << principal << "\n";
	cout << "Annual Interest Rate: " << interest*100 << "%" << "\n";
	cout << "Monthly Payment: $" << std::fixed << std::setprecision(2) << minimumPayment << "\n" << "\n";

	writer << "Starting balance: $" << std::fixed << std::setprecision(2) << principal << "\n";
	writer << "Annual Interest Rate: " << interest*100 << "%" << "\n";
	writer << "Monthly Payment: $" << std::fixed << std::setprecision(2) << minimumPayment << "\n" << "\n";


	// Header
	cout << std::setw(15) << std::left << "Payment";
	cout << std::setw(15) << std::left << "Amount";
	cout << std::setw(15) << std::left << "Interest";
	cout << std::setw(15) << std::left << "Principal";
	cout << std::setw(15) << std::left << "Balance" << "\n" << "\n";

	writer << std::setw(15) << std::left << "Payment";
	writer << std::setw(15) << std::left << "Amount";
	writer << std::setw(15) << std::left << "Interest";
	writer << std::setw(15) << std::left << "Principal";
	writer << std::setw(15) << std::left << "Balance" << "\n" << "\n";


	while(principal > 0)
	{
		// Check if this is the last payment
		if (minimumPayment < (principal + principal*monthlyInterestRate))
		{
			interestPaid +=  floor((monthlyInterestRate*principal) * 100) / 100;	//Rounding off penny fractions
			++paymentsMade;


			cout << std::setw(15) << std::fixed << std::setprecision(2) << paymentsMade;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << paymentsMade;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << minimumPayment;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << minimumPayment;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << monthlyInterestRate*principal;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << monthlyInterestRate*principal;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << (minimumPayment - monthlyInterestRate*principal);
			writer << std::setw(15) << std::fixed << std::setprecision(2) << (minimumPayment - monthlyInterestRate*principal);

			//Principal portion of the payment and rounding off penny fractions
			principal-= ceil((minimumPayment - monthlyInterestRate*principal) * 100) / 100;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << principal << "\n";
			writer << std::setw(15) << std::fixed << std::setprecision(2) << principal << "\n";

		}
		else	// Last payment calculation
		{
			interestPaid +=  floor((monthlyInterestRate*principal) * 100) / 100;	//Rounding off penny fractions
			++paymentsMade;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << paymentsMade;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << paymentsMade;

			cout << std::setw(15) << std::fixed << std::setprecision(2) << (principal + principal*monthlyInterestRate);
			writer << std::setw(15) << std::fixed << std::setprecision(2) << (principal + principal*monthlyInterestRate);

			cout << std::setw(15) << std::fixed << std::setprecision(2) << (monthlyInterestRate*principal);
			writer << std::setw(15) << std::fixed << std::setprecision(2) << (monthlyInterestRate*principal);

			cout << std::setw(15) << std::fixed << std::setprecision(2)	<< principal;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << principal;

			principal = 0; //All paid off

			cout << std::setw(15) << std::fixed << std::setprecision(2) << principal;
			writer << std::setw(15) << std::fixed << std::setprecision(2) << principal;

			cout << "\n\n";
			writer	<< "\n\n";


			cout << "Total Payments Made: " << paymentsMade << "\n";
			writer << "Total Payments Made: " << paymentsMade << "\n";

			cout << std::fixed << std::setprecision(2) << "Total Interest Paid: " << interestPaid << "\n\n\n\n";
			writer << std::fixed << std::setprecision(2) << "Total Interest Paid: " << interestPaid << "\n\n\n\n";

		}

	}

}


