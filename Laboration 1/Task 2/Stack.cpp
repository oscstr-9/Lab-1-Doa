#include "Stack.h"
Stack::Stack(int size) {
	word = new char[size];
}

Stack::~Stack() {
		delete[] word;
}
// takes char, adds to stack
void Stack::addToStack(char letter) {
	word[letterIndex] = letter; // adds to back
	letterIndex++;
}

// returns last char in array
char Stack::takeFromStack() {
	char returnValue = word[letterIndex-1]; // saves value from back to return
	letterIndex--;
	return returnValue;
}