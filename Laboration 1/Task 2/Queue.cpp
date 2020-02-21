#include "Queue.h"
#include <ioStream>

Queue::Queue(int size) {
	word = new char[size];
}
Queue::~Queue() {
	delete[] word;
}

void Queue::addToQueue(char letter) {
	word[letterIndex] = letter; // adds to back
	letterIndex++;
}

char Queue::takeFromQueue() {
	char returnValue = word[0];
	for (int i = 0; i < letterIndex; i++) {
		word[i] = word[i + 1]; // moves list forward
	}
	letterIndex--;
	return returnValue;
}