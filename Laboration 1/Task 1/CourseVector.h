#pragma once
#include <iostream>
class CourseVector
{
	std::string courseName;
	std::string courseCredit;
	std::string courseGrade;
public:
	CourseVector();
	CourseVector(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIns);
	std::string getCourseName();
};