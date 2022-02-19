#pragma once

typedef struct Unit
{
	int data = 0; // count 
	Unit* prev = 0; // pointer to the previous element
};

class Queue
{
private:
	Unit* last = 0; // pointer to the end of the queue
protected:
	int size; // size of Queue
	
public:
	

	Queue();
	~Queue();
	
	Unit* getLast();
	int pop();
	void push(int a);
	void print();
	void copy(Queue& Q);
	void merge(Queue& Q);
	bool isEmpty();

};

