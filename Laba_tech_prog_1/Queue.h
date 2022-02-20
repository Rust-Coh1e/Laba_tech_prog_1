#pragma once

typedef struct Node
{
	int data = 0; // count 
	Node* prev = nullptr; // pointer to the previous element
};

class Queue
{
private:
	Node* last = nullptr; // pointer to the end of the queue
protected:
	int size; // size of Queue
	
public:
	

	Queue();
	~Queue();
	
	Node* getLast();
	int pop();
	void push(int a);
	void print();
	void copy(Queue& Q);
	void merge(Queue& Q);
	bool isEmpty();

};

