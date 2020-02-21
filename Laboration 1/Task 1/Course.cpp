#include "Course.h"
#include <string>

Course::Course(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIn) {
	courseName = courseNameIn;
	courseCredit = courseCreditIn;
	courseGrade = courseGradeIn;
}

std::string Course::getCourseName() {
	return courseName;
}

Course* Course::getNext() {
	return next;
}

void Course::setNext(Course *newNext) {
	next = newNext;
}