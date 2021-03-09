#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//Five different arrays for each data type in the file, all in size 10.
const int SIZE = 10;
int ID[SIZE];
string First[SIZE];
string Last[SIZE];
float saving[SIZE];
float checking[SIZE];

//Function that prints a table of the customers data.
void printCustomersData(int number)
{
	int i;

	cout << left << setw(10) << "LastName" << left << setw(10) << "First Name" << left << setw(10) << "ID";
	cout << left << setw(10) << "Saving Account" << left << setw(10) << "Checking Account.";

	for (i = 0; i < number; i++)
	{
		cout << "\n" << left << setw(10) << Last[i] << left << setw(10) << First[i] << left << setw(10) << ID[i];
		cout << left << setw(10) << saving[i] << left << setw(10) << checking[i];
	}
}

//Function that prints customers' names in alphabetic order by their last name.
void printNames(int number)
{
	string val;
	int i;
	string temp1;
	string temp2;
	string otherLastName[10];
	string otherFirstName[10];

	cout << endl << "Customers by last name:";

	for (i = 0; i < number; i++)
	{
		otherLastName[i] = Last[i];
		otherFirstName[i] = First[i];
	}

	//For loop that sorts names by alphabetical order.
	for (i = 0; i < number - 1; i++)
	{
		for (int j = i + 1; j < number; j++)
		{
			if (otherLastName[i] > otherLastName[j])
			{
				temp1 = otherLastName[i];
				otherLastName[i] = otherLastName[j];
				otherLastName[j] = temp1;
				temp2 = otherFirstName[i];
				otherFirstName[i] = otherFirstName[j];
				otherFirstName[j] = temp2;
			}
		}
	}

	for (i = 0; i < number; i++)
	{
		cout << endl << left << setw(10) << otherFirstName[i] << left << setw(10) << otherLastName[i];
	}
}

//Function that adds & displays the balances of all customers' saving & checking account.
void printBankTotal(int number)
{
	int i;
	float totalSaving = 0;
	float totalChecking = 0;

	for (i = 0; i < number; i++)
	{
		totalSaving = totalSaving + saving[i];
		totalChecking = totalChecking + checking[i];
	}

	cout << endl;
	cout << fixed << setprecision(2) << "Summation balance of all customers' saving accounts: $" << totalSaving;
	cout << endl;
	cout << fixed << setprecision(2) << "Summation balance of all customers' checking accounts: $" << totalChecking;
}

//Function Calls
void printCustomersData(int number);
void printNames(int number);
void printBankTotal(int number);

