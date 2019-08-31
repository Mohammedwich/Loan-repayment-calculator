//============================================================================
// Name			: cs1337F19p1.h
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


#ifndef CS1337F19P1_H_
#define CS1337F19P1_H_

#include <iostream>
#include <fstream>


void calculateRepayment(double principal, double interest, double minimumPayment, std::ofstream & writer);


#endif /* CS1337F19P1_H_ */
