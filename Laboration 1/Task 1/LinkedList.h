#pragma once
#include "Student.h"
#include "Course.h"
#include <iostream>


class LinkedList
{
	Student *studentHead;
	int amountOfStudents = 0;
public:
	LinkedList(Student *studentHeadIn);
	LinkedList(Course *courseHeadIn);
	bool addStudent(Student *student);
	bool addCourse(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIn, int studentPos);
	bool removeStudent(int studentPos);
	bool removeCourse(int coursePos, int studentPos);
	Student* studentAt(int pos);
	Course* courseAt(int coursePos, int studentPos);
};

