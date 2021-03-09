#pragma once
#include <iostream>
using namespace std;

//Declares student class with public constructors & private methods to store names, quiz & exam scores
class Student 
{
public:
	Student();
	bool ReadData(istream& in);
	bool WriteData(ostream& out) const;
	string GetFirstName();
	string GetLastName();
	float CourseAverage() const;
	bool DisplayCourseAverage(ostream& out) const;
	string LetterGrade() const;

private:
	string first;
	string last;
	int quizScores[5];
	int examScores[3];
};
