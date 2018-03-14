#ifndef STACK_H
#define STACK_H

class Stack
{
	private:
		static const long SIZE = 10;
		long ary[SIZE];
		long top;

	public:
		void push(long);
		long pop();
		long peek() const;
		bool isEmpty() const;
		bool isFull() const;
		Stack();
};
#endif
