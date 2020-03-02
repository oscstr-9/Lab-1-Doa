#include "LinkedList.h"
#include <string>

LinkedList::LinkedList(Student* studentHeadIn) {
	studentHead = studentHeadIn;
}
// takes student pointer, adds student pointer to the end of linked list // returns  true if works
bool LinkedList::addStudent(Student* student) {
	Student* targetStudent = studentHead;
	studentHead = student;
	student->setNext(targetStudent);
	amountOfStudents++;

	return true;
}

// takes different course information and the position of the student the course will be given to // returns true if it works
bool LinkedList::addCourse(std::string courseNameIn, std::string courseCreditIn, std::string courseGradeIn, int studentPos) {
	Student* targetStudent = studentHead;

	for (int i = 0; i < studentPos; i++) { //traverses forward in linked list
		targetStudent = targetStudent->getNext();
	}
	Course* course = new Course(courseNameIn, courseCreditIn, courseGradeIn);

	Course* targetCourse = targetStudent->getCourseHead();
	targetStudent->setCourseHead(course); //set head to be new course
	course->setNext(targetCourse); //set new courses next to what head was
	targetStudent->setAmountOfCourses(1);

	return true;
}
// takes student position, removes found student // returns true if works
bool LinkedList::removeStudent(int studentPos) {
	Student* targetStudent = studentHead;
	Student* tempStudent;

	if (studentPos > amountOfStudents) {
		std::cout << "Out of student index!" << std::endl;
		return false;
	}

	if (studentPos == 0) { // if list is empty
		tempStudent = targetStudent;
		studentHead = targetStudent->getNext();
	}
	else {
		for (int i = 0; i < studentPos - 1; i++) { // if list is not empty
			targetStudent = targetStudent->getNext();
		}
		tempStudent = targetStudent->getNext();
		targetStudent->setNext(tempStudent->getNext());

	}
	//delete tempStudent;
	amountOfStudents--;
	
	return true;
}

// takes position of student and position of the course in the student to be removed // returns true if works
bool LinkedList::removeCourse(int coursePos, int studentPos) {
	Student* targetStudent = studentHead;
	Course* targetCourse = targetStudent->getCourseHead();
	Course* tempCourse;

	if (studentPos > amountOfStudents) {
		std::cout << "Out of student index!" << std::endl;
		return false;
	}

	if (coursePos > targetStudent->getAmountOfCourses()) {
		std::cout << "Out of course index!" << std::endl;
		return false;
	}

	if (coursePos == 0) {
		for (int i = 0; i < studentPos; i++) {

			targetStudent = targetStudent->getNext();

		}
		tempCourse = targetCourse;
		targetStudent->setCourseHead(targetCourse->getNext());
	}
	else {
		for (int i = 0; i < studentPos; i++) {
			targetStudent = targetStudent->getNext();
		}

		if (studentPos > coursePos > targetStudent->getAmountOfCourses()) {
			std::cout << "Out of course index!" << std::endl;
			return false;
		}

		for (int j = 0; j < coursePos - 1; j++) {
			targetCourse = targetCourse->getNext();
		}
		tempCourse = targetCourse->getNext(); //sets to be removed course as temp var
		targetCourse->setNext(tempCourse->getNext()); //sets new next as to be removeds next

	}
	delete tempCourse;
	targetStudent->setAmountOfCourses(-1);

	return true;
}
// takes student position // returns found student
Student* LinkedList::studentAt(int studentPos) {
	Student* targetStudent = studentHead;
	if (studentPos > amountOfStudents) {
		std::cout << "Out of index!" << std::endl;
		return false;
	}

	for (int i = 0; i < studentPos; i++) {
		targetStudent = targetStudent->getNext();
	}
	return targetStudent;
}

// takes student position and position of course to be looked for // returns found course
Course* LinkedList::courseAt(int coursePos, int studentPos) {
	Student* targetStudent = studentHead;
	Course* targetCourse = targetStudent->getCourseHead();

	if (studentPos > amountOfStudents - 1) {
		std::cout << "Out of student index!" << std::endl;
		return false;
	}
	for (int i = 0; i < studentPos; i++) {
		targetStudent = targetStudent->getNext();
	}

	if (coursePos > targetStudent->getAmountOfCourses() - 1) {
		std::cout << "Out of course index!" << std::endl;
		return false;
	}
	for (int j = 0; j < coursePos; j++) {
		targetCourse = targetCourse->getNext();
	}
	return targetCourse;
}

