#ifndef STACKLLZY_H
#define STACKLLZY_H

template <class T>
class Stack
{
	private:
		struct StackNode
		{
			StackNode* nextNodePtr;
			T dataVal;
		};
		StackNode *head, *tail;

		//functions from book.  Used, but never called from the main
		void listRemoveAfter(StackNode*&, StackNode*&, StackNode*);
		void listPrepend(StackNode*&, StackNode*&, StackNode*);

	public:
		Stack();  //constructor
		~Stack();  //destructor
		void push(T);
		T pop();
		bool isEmpty() const;

};

template <class T>
bool Stack<T>::isEmpty() const
{
	//stack is empty if head is null (list is empty)
	return head == nullptr;
}

//constructor to initialize empty list
template <class T>
Stack<T>::Stack()
{
	head = tail = nullptr;
}

template <class T>
T Stack<T>::pop()
{
	T poppedVal = head->dataVal;    // Copy value of list head (top of stack)
	listRemoveAfter(head, tail, nullptr);  // Remove list head  
	return poppedVal;
}

template <class T>
void Stack<T>::push(T val)
{
	StackNode* newNode;
	newNode = new StackNode;
	newNode->dataVal = val;
	newNode->nextNodePtr = nullptr;
	listPrepend(head, tail, newNode);
}

//destructor
template <class T>
Stack<T>::~Stack()
{
	StackNode* temp, *toDelete;
	temp = head;
	while (temp != nullptr)
	{
		toDelete = temp;
		temp = temp->nextNodePtr;
		delete toDelete;
	}

	head = tail = nullptr;
}

//adapted from book
template <class T>
void Stack<T>::listRemoveAfter(StackNode* & head, StackNode*& tail, StackNode* curNode) {
	StackNode* sucNode, *toDelete;

	// Special case, remove head
	if (curNode == nullptr && head != nullptr) {
		sucNode = head->nextNodePtr;
		toDelete = head;
		head = sucNode;

		if (sucNode == nullptr) { // Removed last item
			tail = nullptr;
		}
	}
	else if (curNode->nextNodePtr != nullptr) {
		toDelete = curNode->nextNodePtr;
		sucNode = curNode->nextNodePtr->nextNodePtr;
		curNode->nextNodePtr = sucNode;

		if (sucNode == nullptr) { // Removed tail
			tail = curNode;
		}
	}

	delete toDelete;
}

//adapted from book
template <class T>
void Stack<T>::listPrepend(StackNode*& h, StackNode*& t, StackNode* n)
{
	if (h == nullptr)
	{
		h = n;
		t = n;
	}
	else
	{
		n->nextNodePtr = h;
		h = n;
	}
}
#endif
