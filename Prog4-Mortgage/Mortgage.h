#pragma once
// header file for Mortgage class

class Mortgage
{
	private:
		int loan; // amount of loan
		int year; // number of years
		float rate; // annual interest rate
		double term; // holds calculated term
		void termCalc(); // calculates the term
	public:
		Mortgage(int,int,float); // constructor to hold input
		double monthPay(); // calculates monthly pay
		double totalAmount(); // calculates the total amount of the loan
};
