#pragma once
class Stack
{
	char* word;
	int letterIndex = 0;
public:
	Stack(int size);
	void addToStack(char letter);
	char takeFromStack();
	~Stack();
};

