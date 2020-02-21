#include "LinkedList.h"
#include "StudentVector.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <Chrono>

using namespace std;

void main() {
	Student* studentHead = nullptr;
	LinkedList list(studentHead);
	int itterarions = 0;
	cin >> itterarions;
	cout << "Linked list:" << endl;
	for (int i = 1; i <= 4; i++) { // switch case to test all methods once each
		auto start = chrono::high_resolution_clock().now();

		switch (i)
		{
		case(1): {
			for (int j = 0; j < itterarions; j++) {
				Student student = Student("bob" + i);
				list.addStudent(&student);
			}
			break;
		}
		case(2): {
			for (int k = 0; k < itterarions; k++) {
				for (int j = 0; j < itterarions; j++) {
					list.addCourse("base" + j, "none" + j, "SS++" + j, k);
				}
			}
			break;
		}
		case(3): {
			for (int k = 0; k < itterarions; k++) {
				for (int j = 0; j < itterarions; j++) {
					list.removeCourse(0, k);
				}
			}
			break;
		}
		case(4): {
			for (int j = 0; j < itterarions; j++) {
				list.removeStudent(0);
			}
			break;
		}

		default:
			break;
		}

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}

	cout << endl << endl;

	vector<StudentVector> students;
	cout << "Vector list:" << endl;
	for (int i = 1; i <= 4; i++) {
		auto start = chrono::high_resolution_clock().now();

		switch (i)
		{
		case(1): {
			for (int j = 0; j < itterarions; j++) {
				StudentVector studentVector("Ben" + j);
				students.insert(students.begin(), studentVector);
			}
			break;
		}
		case(2): {
			for (int k = 0; k < itterarions; k++) {
				for (int j = 0; j < itterarions; j++) {
					students[k].addVectorCourse("base", "none", "SS++");
				}
			}
			break;
		}

		case(3): {
			for (int k = 0; k < itterarions; k++) {
				for (int j = 0; j < itterarions; j++) {
					students[k].removeCourse(0);
				}
			}
			break;
		}
		case(4): {
			for (int j = 0; j < itterarions; j++) {
				students.erase(students.begin());
			}
			break;
		}
		default:
			break;
		}

		auto stop = chrono::high_resolution_clock().now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
		cout << duration << " microseconds elapsed." << endl;
	}
}