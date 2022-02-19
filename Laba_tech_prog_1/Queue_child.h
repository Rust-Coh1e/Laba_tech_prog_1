#pragma once
#include "Queue.h"

class Queue_private : private Queue
{
public:
	float average();
	int pop(); //
	void push(int a); //
	void print(); 
	void merge(Queue_private& Q); //
	void copy(Queue_private& Q); 
	bool isEmpty(); //
};

class Queue_protected : protected Queue
{
public:
	float average();
	int pop(); //
	void push(int a); //
	void print();
	void merge(Queue_protected& Q); //
	void copy(Queue_protected& Q);
	bool isEmpty(); //
};

class Queue_public : public Queue
{
public:
	float average();
};