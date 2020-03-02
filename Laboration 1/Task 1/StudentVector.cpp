#include "StudentVector.h"
#include "CourseVector.h"
#include <string>

StudentVector::StudentVector(std::string studentNameIn) {
	studentName = studentNameIn;
	std::vector<CourseVector> courses;
}

std::string StudentVector::getStudentName() {
	return studentName;
}
// takes course information, creates course and adds to students course vector
void StudentVector::addVectorCourse(std::string courseName, std::string courseCredit, std::string courseGrade) {
	CourseVector course(courseName, courseCredit, courseGrade);
	courses.insert(courses.begin(), course);
}
// removes course at given position
void StudentVector::removeCourse(int coursePos) {
	courses.erase(courses.begin()+coursePos);
}

CourseVector StudentVector::getCourse(int coursePos) {
	return courses[coursePos];
}

StudentVector::~StudentVector() {
	
}
