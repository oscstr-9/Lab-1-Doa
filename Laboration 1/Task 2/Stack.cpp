#include "Stack.h"
Stack::Stack(int size) {
	word = new char[size];
}

Stack::~Stack() {
		delete[] word;
}

void Stack::addToStack(char letter) {
	word[letterIndex] = letter; // adds to back
	letterIndex++;
}

char Stack::takeFromStack() {
	char returnValue = word[letterIndex-1]; // saves value from back to return
	letterIndex--;
	return returnValue;
}