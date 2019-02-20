// implementation file for Mortgage class
#include "Mortgage.h"
#include <iomanip>
using namespace std;

//===========================================================================
// Mortgage: Constructor that places user input into private data
// parameters:
//		loanIn: int variable that holds users loan input
//		yearIn: int variable that holds users year input
//		rateIn: float variable that holds users annual interest rate input
// return type: N/a
//===========================================================================
Mortgage::Mortgage(int loanIn,int yearIn,float rateIn)
{
	loan = loanIn; // loan input to private data
	year = yearIn; // year input to private data
	rate = rateIn; // rate input to private data
}

//===========================================================================
// monthPay: calculates the monthly pay of the mortgage and returns the value
// parameters:
//		N/A
// return type: double
//===========================================================================
double Mortgage::monthPay()
{
	double payment; // var to hold calculated monthly pay

	termCalc(); // calculates the term value

	payment = (loan * (rate / 12) * term) / (term - 1); // calculates payment

	return payment;
}

//===========================================================================
// totalAmount: calculates the total pay of the home mortgage
// parameters:
//		N/A
// return type: double
//===========================================================================
double Mortgage::totalAmount()
{
	double totalAmount; // holds total amount calculated
	double payment; // holds monthly payment calculated

	termCalc(); // calculates term

	payment = (loan * (rate / 12) * term) / (term - 1); // calculates and stores in payment
	totalAmount = payment * (year * 12); // calculates total amount 

	return totalAmount; 
}

//===========================================================================
// termCalc: calculates the term value in private data
// parameters:
//		N/A
// return type: void
//===========================================================================
void Mortgage::termCalc()
{
	term = pow((1 + (rate / 12)), (12 * year)); // calculates term and stores in private data
}