//====================================================================
// Joshua Murray
// Due Friday, February 20
// Programming II: Assigment #4
// Description: Program that calculates the monthly and total payment on a home mortgage
//====================================================================
#include <iostream>
#include <iomanip>
#include <string>
#include "Mortgage.h"
using namespace std;

bool parseInt(string, int&);
bool parseFloat(string, float&);
int loanInput();
int yearInput();
float rateInput();

int main()
{
	int loanInt, // holds the loan amount
		yearInt; // holds how many years 
	float rateF; // holds what the annual rate is
	double payment, // holds the monthly payment
		totalAmount; // holds the total amount to be paid

	loanInt = loanInput(); //calls loan input function to put into loanInt
	yearInt = yearInput(); //calls year input function to put into yearInt
	rateF = rateInput(); //calls rate input function to put into rateF

	Mortgage input(loanInt, yearInt, rateF); //constructor for input
	payment = input.monthPay(); // calculates monthly pay and put it into variable
	totalAmount = input.totalAmount(); // calculates the total amount and puts it into variable

	cout << fixed << showpoint << setprecision(2);
	cout << "Your monthly payment is: $" << payment << endl; // displaying monthly payment
	cout << "The total amount paid is: $" << totalAmount << endl; // displaying total amount

	return 0;
}

//===========================================================================
// loanInput: asks user for the loan amount and tests input to see if its valid, if invalid,
//			 asks user to input code until valid, once valid, returns loanInt back to main
// parameters:
//		N/A
// return type: int
//===========================================================================
int loanInput()
{
	string loanString; // holds the input from user
	bool valInt; // holds bool value whether input is valid
	int loanInt; // holds valid input

	cout << "What is the loan amount: ";
	getline(cin, loanString);
	valInt = parseInt(loanString, loanInt); // checks input from user

	while (!valInt || loanInt <= 0) // validation until user inputs valid input
	{
		cout << "Invalid input, What is the loan amount: ";
		getline(cin, loanString);
		valInt = parseInt(loanString, loanInt);
	}

	return loanInt; // returns loanint back to main
}

//===========================================================================
// yearInput: asks user for the years of the loan and tests input to see if its valid, if invalid,
//			 asks user to input code until valid, once valid, returns yearInt back to main
// parameters:
//		N/A
// return type: int
//===========================================================================
int yearInput()
{
	string yearString; // holds the input of year from the user
	bool valInt; // holds whether the input is valid or not
	int yearInt; // holds the valid input from the user

	cout << "How many years of the loan: ";
	getline(cin, yearString);
	valInt = parseInt(yearString, yearInt); // validating input from user

	while (!valInt || yearInt <= 0) // runs loop until valid input is inputted
	{
		cout << "Invalid input, how many years of the loan: ";
		getline(cin, yearString);
		valInt = parseInt(yearString, yearInt);
	}

	return yearInt; // returns year amount back to main once valid
}

//==========================================================================
// rateInput: asks user for the annual interest rate and tests input to see if its valid, if invalid,
//			 asks user to input code until valid, once valid, returns rateF back to main
// parameters:
//		N/A
// return type: float
//===========================================================================
float rateInput()
{
	string rateString; // holds input from user of the rate
	bool valDoub; // bool var to say whether the input is valid or not
	float rateF; // input after passed through validator

	cout << "What is the annual interest rate: ";
	getline(cin, rateString);
	valDoub = parseFloat(rateString, rateF); // passes input into validator

	while (!valDoub || rateF <= 0) // runs validation until input is valid
	{
		cout << "Invalid input, what is the annual interest rate: ";
		getline(cin, rateString);
		valDoub = parseFloat(rateString, rateF);
	}

	return rateF/100; // returns valid rate input
}

//===========================================================================
// parseInt: given a string, sees if it can turn the string into an int. If it can't, catches error and returns a bool of false
//			 If it is able to convert, makes val that number and returns that it successfully changed it
// parameters:
//	sval: string variable holding the input from the user to be tested
//	 val: pass by refernce to hold the int transfered from the string
// return type: bool
//===========================================================================
bool parseInt(string sval, int& val)
{
	int num; // var to hold string once its changed to an int
	bool success = true; // bool var to hold whether or not the number is a real number
	try
	{
		num = stoi(sval);  // checks if the string can be changed to an int
		val = num; // sets val equalls to num
	}
	catch (const std::exception&)
	{
		success = false; // if fails, sets success to false
	}
	return success; // returns the bool
}

//===========================================================================
// parseFloat: given a string, sees if it can turn the string into an float. If it can't, catches error and returns a bool of false
//			 If it is able to convert, makes val that number and returns that it successfully changed it
// parameters:
//	sval: string variable holding the input from the user to be tested
//	 val: pass by refernce to hold the float transfered from the string
// return type: bool
//===========================================================================
bool parseFloat(string sval, float& val)
{
	float num; // var to hold string once its changed to a float
	bool success = true; // bool var to hold whether or not the number is a real number
	try
	{
		num = stof(sval); // checks if the string can be changed to an float
		val = num; // sets val equalls to num
	}
	catch (const std::exception&)
	{
		success = false; // if fails, sets success to false
	}
	return success; // returns the bool
}