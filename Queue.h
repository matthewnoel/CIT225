// Working Queue Class Implemented as an array
// Written by Dr. Thompson
// April 26, 2018

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
	static const long MAX_SIZE = 100;
	long rear, front, numItems;
	T ary[MAX_SIZE];

public:
	Queue();
	void push(T);
	T pop();
	T peek();
	bool isEmpty();
	bool isFull();

};


template <class T>
Queue<T>::Queue()
{
	numItems = 0;
	rear = -1;
	front = 0;
}


template <class T>
bool Queue<T>::isEmpty()
{
	return numItems == 0;
}

template <class T>
bool Queue<T>::isFull()
{
	return numItems == MAX_SIZE;
}

template <class T>
void Queue<T>::push(T val)
{
	if (!isFull())
	{
		numItems++;
		if (rear < MAX_SIZE - 1)
		{
			rear++;
		}
		else
		{
			rear = 0;
		}
		ary[rear] = val;
	}
}

template <class T>
T Queue<T>::peek()
{
	return ary[front];
}


template <class T>
T Queue<T>::pop()
{
	T temp;
	if (!isEmpty())
	{
		temp = ary[front];
		if (front < MAX_SIZE - 1)
		{
			front++;
		}
		else
		{
			front = 0;
		}

		numItems--;

		return temp;
	}
}
#endif
