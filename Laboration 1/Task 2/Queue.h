#pragma once
class Queue
{
	char* word;
	int letterIndex = 0;
public:
	Queue(int size);
	~Queue();
	void addToQueue(char letter);
	char takeFromQueue();
};

