#include "CourseVector.h"
#include <string>

CourseVector::CourseVector(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIn) {
	courseName = courseNameIn;
	courseCredit = courseCreditIn;
	courseGrade = courseGradeIn;
}

std::string CourseVector::getCourseName() {
	return courseName;
}