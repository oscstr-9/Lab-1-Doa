#pragma once
#include "Course.h"
#include <iostream>
class Student
{
	std::string studentName;
	Student* next;
	Course* courseHead = nullptr;
	int amountOfCourses;
public:
	Student(std::string studentNameIn);
	~Student();
	std::string getStudentName();
	Student *getNext();
	void setNext(Student* newNext);
	Course* getCourseHead();
	void setCourseHead(Course* courseHeadIn);
	int getAmountOfCourses();
	void setAmountOfCourses(int amountOfCoursesChange);
};