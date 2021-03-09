#include "Program4Utility.h"
#include <iomanip>
using namespace std;

//Initializes all data elements: name to empty strings, numeric values to 0
Student::Student() 
{
	first = "";
	last = "";

	for (int i = 0; i < 5; i++)
		quizScores[i] = 0;

	for (int j = 0; j < 3; j++)
		examScores[j] = 0;
}

//Getter that returns first name
string Student::GetFirstName()
{
	return first;
}

//Getter that returns last name
string Student::GetLastName()
{
	return last;
}

//Reads data from data input & returns false if unsuccessful, and true otherwise
bool Student::ReadData(istream& in)
{
	in >> first;
	if (in.fail())
		return false;

	in >> last;
	if (in.fail())
		return false;

	for (int i = 0; i < 5; i++)
	{
		in >> quizScores[i];
		if (in.fail())
			return false;
	}

	for (int j = 0; j < 3; j++)
	{
		in >> examScores[j];
		if (in.fail())
			return false;
	}

	return true;

}

//Outputs data into console: first name & last name left justifed 20 characters
//Quiz & exam scores right justified 4 & 5 characters
//Returns false if unsuccessful, true otherwise
bool Student::WriteData(ostream& out) const
{
	out << left << setw(20) << first;
	if (out.fail())
		return false;

	out << left << setw(20) << last;
	if (out.fail())
		return false;

	for (int i = 0; i < 5; i++)
		out << right << setw(4) << quizScores[i];

	for (int j = 0; j < 3; j++)
		out << right << setw(5) << examScores[j];

	out << endl;

	return true;

}

//Calculates the student's weighted average as a percentage
//Quizzes are 35% of the grade
//Exams are 65% of the grade
float Student::CourseAverage() const
{
	float total = 0;
	float quizzesAverage;
	float examsAverage;
	float classGrade;

	for (int i = 0; i < 5; i++)
	{
		total = total + quizScores[i];
		quizzesAverage = total / 5.0;
	}

	total = 0;

	for (int j = 0; j < 3; j++)
	{
		total = total + examScores[j];
		examsAverage = total / 3.0;
	}

	classGrade = (quizzesAverage * 1.75 + examsAverage * 0.65);

	return classGrade;
}

//Displays student's course average round to 3 decimal places & returns false if unsuccessful, true otherwise
bool Student::DisplayCourseAverage(ostream& out) const
{
	out << fixed << setprecision(3) << CourseAverage();

	if (out.fail())
		return false;
	else
		return true;
}

//Returns letter grade based on student's course average using the same grading scale as this class
string Student::LetterGrade() const
{

	float classGrade = CourseAverage();

	if (classGrade >= 94)
		return "A";
	if (classGrade >= 91)
		return "A-";
	if (classGrade >= 86)
		return "B+";
	if (classGrade >= 81)
		return "B";
	if (classGrade >= 76)
		return "B-";
	if (classGrade >= 71)
		return "C+";
	if (classGrade >= 66)
		return "C";
	if (classGrade >= 61)
		return "C-";
	if (classGrade >= 56)
		return "D+";
	if (classGrade >= 50)
		return "D";
	else
		return "F";
}
