#include "Student.h"
#include "Course.h"
#include "LinkedList.h"
#include <string>

Student::Student(std::string studentNameIn) {
	studentName = studentNameIn;
	LinkedList list(Course* courseHead);
	amountOfCourses = 0;
}

std::string Student::getStudentName() {
	return studentName;
}

Student* Student::getNext() {
	return next;
}

void Student::setNext(Student* newNext) {
	next = newNext;
}

Course* Student::getCourseHead() {
	return courseHead;
}

void Student::setCourseHead(Course* courseHeadIn) {
	courseHead = courseHeadIn;
}
int Student::getAmountOfCourses() {
	return amountOfCourses;
}

void Student::setAmountOfCourses(int amountOfCoursesChange) {
	amountOfCourses += amountOfCoursesChange;
}
// deletes all courses of deleted student as well as the student
Student::~Student() {
	for (int i = 0; i < amountOfCourses; i++) {
		Course* tempCourse = courseHead->getNext();
		delete courseHead;
		courseHead = tempCourse;
	}
}
