#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
	size = 0;
	last = nullptr;
}

Queue::~Queue()
{
	while (size > 0)
	{
		Unit* temp = last;
		last = temp->prev;
		delete temp;
		size--;
	}
}

Unit* Queue::getLast()
{
	return last;
}

void Queue::push(int a)
{
	Unit* new_unit = new Unit;
	new_unit-> prev = last;
	last = new_unit;
	last->data = a;
	size++;
}

int Queue::pop()
{
	Unit* tmp = last;
	int res = 0;
	if (tmp->prev == nullptr)
	{
		res = tmp->data;
		delete tmp;
		last = nullptr;
		size--;
	}
	else
	{
		while (tmp->prev->prev != nullptr) 
		{
			tmp = tmp->prev;
		}
		res = tmp->prev->data;
		delete tmp->prev;
		tmp->prev = nullptr;
		size--;
	}
	return res;
}



void Queue::print()
{
	Unit* tmp = last;
	while (tmp->prev != nullptr)
	{
		cout << tmp->data << " -> ";
		tmp = tmp->prev;
	}
	cout << tmp->data << endl;
};

void Queue::copy(Queue& Q)
{
	int* tmp = new int[Q.size];
	Unit* queue = Q.last;
	for (int i = Q.size - 1; i >= 0; i--)
	{
		tmp[i] = queue->data;
		queue = queue->prev;
	}
	for (int i = 0; i < Q.size; i++)
	{
		this->push(tmp[i]);
	}
	delete[] tmp;
	cout << "copying completed!" << endl;
};

void Queue::merge(Queue& Q)
{
	int* tmp = new int[Q.size];
	Unit* queue = Q.last;
	for (int i = Q.size - 1; i >= 0; i--)
	{
		tmp[i] = queue->data;
		queue = queue->prev;
	}
	for (int i = 0; i < Q.size; i++)
	{
		this->push(tmp[i]);
	}
	delete[] tmp;
	cout << "merging completed!" << endl;
};

bool Queue::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}