#pragma once
#include "CourseVector.h"
#include <iostream>
#include <vector>
class StudentVector
{
	std::string studentName;
	std::vector<CourseVector> courses;
public:
	StudentVector(std::string studentNameIn);
	~StudentVector();
	std::string getStudentName();
	void addVectorCourse(std::string courseName, std::string courseCredit, std::string courseGrade);
	void removeCourse(int coursePos);
	CourseVector getCourse(int coursePos);
};