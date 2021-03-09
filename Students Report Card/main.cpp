//Iradiel Torres
//Program 04
//11/01/2020

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Program4Utility.h"
using namespace std;


//Function to sort by student's last name
void sort(vector<Student>& students) 
{
	for (int i = 0; i < students.size() - 1; i++)
	{
		for (int j = i + 1; j < students.size(); j++)
		{
			if (students[i].GetLastName() > students[j].GetLastName())
			{
				Student student = students[i];
				students[i] = students[j];
				students[j] = student;
			}
		}
	}
}


int main()
{
	//Declares student vector to add student's data from file
	vector<Student> students;
	Student student;
	int data;

	fstream in;
	in.open("Program4Data.txt");

	if (in.fail())
	{
		cout << "Cannot open file.";
		exit(0);
	}

	in >> data;

	//Pushes data into student vector for each data the student has
	for (int i = 0; i < data; i++)
	{
		student.ReadData(in);
		students.push_back(student);
	}

	//Calls sort function
	sort(students);

	//Displays roster including name, course average to 3 decimal places & letter grade for each student
	for (int i = 0; i < data; i++)
	{
		cout << fixed << setprecision(3);
		cout << left << setw(20) << students[i].GetFirstName();
		cout << left << setw(20) << students[i].GetLastName();
		cout << left << setw(20) << students[i].CourseAverage();
		cout << students[i].LetterGrade();
		cout << endl;
	}

	return 0;
}

