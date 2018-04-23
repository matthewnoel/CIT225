#ifndef QUEUELLZY_H
#define QUEUELLZY_H

template <class T>
class Queue
{
private:
        struct QueueNode
        {
                QueueNode* nextNodePtr;
                T dataVal;
        };
        QueueNode *head, *tail;

        //functions from book.  Used, but never called from the main
        void listRemoveAfter(QueueNode*&, QueueNode*&, QueueNode*);
        void listPrepend(QueueNode*&, QueueNode*&, QueueNode*);

public:
        Queue();  //constructor
        ~Queue();  //destructor
        void push(T);
        T pop();
        bool isEmpty() const;

};

template <class T>
bool Queue<T>::isEmpty() const
{
        //queue is empty if head is null (list is empty)
        return head == nullptr;
}

//constructor to initialize empty list
template <class T>
Queue<T>::Queue()
{
        head = tail = nullptr;
}

template <class T>
T Queue<T>::pop()
{
        T poppedVal = head->dataVal;    // Copy value of list head (top of stack)
        listRemoveAfter(head, tail, nullptr);  // Remove list head  
        return poppedVal;
}

template <class T>
void Queue<T>::push(T val)
{
        QueueNode* newNode;
        newNode = new QueueNode;
        newNode->dataVal = val;
        newNode->nextNodePtr = nullptr;
        listPrepend(head, tail, newNode);
}

//destructor
template <class T>
Queue<T>::~Queue()
{
        QueueNode* temp, *toDelete;
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
void Queue<T>::listRemoveAfter(QueueNode* & head, QueueNode*& tail, QueueNode* curNode) {
        QueueNode* sucNode, *toDelete;

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
void Queue<T>::listPrepend(QueueNode*& h, QueueNode*& t, QueueNode* n)
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
