#include "Stack.h"

void Stack::push(long val)
{
	top = top + 1;
	ary[top] = val;
	//ary[++top] = val;
}

long Stack::pop()
{
	top = top - 1;
	return ary[top+1];
	//return ary[top--];
}

long Stack::peek() const
{
	return ary[top];
}

bool Stack::isFull() const
{
	if (top == SIZE - 1)
		return true;
	else
		return false;
	//return top == SIZE-1;
}

bool Stack::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
	//return top == -1;
}

Stack::Stack()
{
	top = -1;
}