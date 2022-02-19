#include <iostream>
#include "Queue_child.h"

using namespace std;

float Queue_private::average()
{
	Unit* last = getLast();
	float avarage = 0;
	float res;
	if (size == 0)
	{
		cout << "queue is empty" << endl;
		return 0;
	}
	else
	{
		while (last->prev != nullptr)
		{
			avarage += last->data;
			last = last->prev;
		}
		avarage += last->data;
	}
	res = avarage / size;
	return res;
}

float Queue_protected::average()
{
	Unit* last = getLast();
	float avarage = 0;
	float res;
	if (size == 0)
	{
		cout << "queue is empty" << endl;
		return 0;
	}
	else
	{
		while (last->prev != nullptr)
		{
			avarage += last->data;
			last = last->prev;
		}
		avarage += last->data;
	}
	res = avarage / size;
	return res;
}

float Queue_public::average()
{
	Unit* last = getLast();
	float avarage = 0;
	float res;
	if (size == 0)
	{
		cout << "queue is empty" << endl;
		return 0;
	}
	else
	{
		while (last->prev != nullptr)
		{
			avarage += last->data;
			last = last->prev;
		}
		avarage += last->data;
	}
	res = avarage / size;
	return res;
}

int Queue_private::pop() { return Queue::pop(); }

void Queue_private::push(int a) { return Queue::push(a); }

void Queue_private::print() { return Queue::print(); }

void Queue_private::merge(Queue_private& Q) { return Queue::merge(Q); }

void Queue_private::copy(Queue_private& Q) { return Queue::copy(Q); }

bool Queue_private::isEmpty() { return Queue::isEmpty(); }


int Queue_protected::pop() { return Queue::pop(); }

void Queue_protected::push(int a) { return Queue::push(a); }

void Queue_protected::print() { return Queue::print(); }

void Queue_protected::merge(Queue_protected& Q) { return Queue::merge(Q); }

void Queue_protected::copy(Queue_protected& Q) { return Queue::copy(Q); }

bool Queue_protected::isEmpty() { return Queue::isEmpty(); }


