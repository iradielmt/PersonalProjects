//Iradiel Torres
//10/18/2020

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Program3Utility.h"
using namespace std;


int main()
{
	ifstream fin;
	char choice;
	int number = 0;

	fin.open("input.txt");

	//Prints message if file cannot be opened.
	if (fin.fail())
	{
		cout << endl << "Cannot open file.";
		exit(0);
	}

	//Reads file data into arrays.
	while (fin >> ID[number] >> First[number] >> Last[number] >> saving[number] >> checking[number])
	{
		number += 1;
	}

	fin.close();

	cout << endl;
	cout << "1. Print customer information";
	cout << endl;
	cout << "2. Print all customer Names ordered by their Last Name.";
	cout << endl;
	cout << "3. Print Bank's total amount.";
	cout << endl;
	cout << "4. Enter q/Q to quit" << endl;

	cin >> choice;

	while (!(choice == 'q' || choice == 'Q'))
	{
		switch (choice)
		{
		case '1':
			printCustomersData(number);
			break;

		case '2':
			printNames(number);
			break;

		case '3':
			printBankTotal(number);
			break;

		case '4':break;

		//Displays error message if anything other than 1, 2, 3, or 4 is entered.
		default: cout << endl << "Incorrect input. Enter another option. ";
			break;
		}

		cout << endl << endl;
		cout << "1. Print customer information";
		cout << endl;
		cout << "2. Print all customer Names ordered by their Last Name.";
		cout << endl;
		cout << "3. Print Bank's total amount.";
		cout << endl;
		cout << "4. Enter q/Q to quit" << endl;

		cin >> choice;
	}
	return 0;
}

