#pragma once
#include <iostream>
class Course
{
	std::string courseName;
	std::string courseCredit;
	std::string courseGrade;
	Course *next;
public:
	Course();
	Course(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIns);
	std::string getCourseName();
	Course *getNext();
	void setNext(Course *newNext);
};