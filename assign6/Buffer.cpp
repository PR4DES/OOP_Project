// Buffer.cpp

#include <iostream>
#include "Buffer.h"
using namespace std;

// public functions
//	1. constructors
//	2. destructor
//	3. get funtions
//	4. produce functions
//	5. consume functions
Buffer::Buffer()
{
	count = 0;
	head = NULL;
	tail = NULL;
}
Buffer::Buffer(const Buffer& other)
{
	count = other.count;
	copy(other);
}
Buffer::~Buffer()
{
	if(count != 0) clear();
}
Buffer& Buffer::operator=(const Buffer& original)
{
	count = original.count;
	copy(original);
	return *this;
}
Node* Buffer::getHead()
{
	return head;
}
Node* Buffer::getTail()
{
	return tail;
}
std::string Buffer::getHeadElement()
{
	return head->getWord();
}
std::string Buffer::getTailElement()
{
	return tail->getWord();
}
void Buffer::produceAtHead(const std::string str)
{
	if(head==NULL) // if there are no node
	{
		head = new Node(str);
		tail = head;
	}
	else
	{
		Node* ptr = head;
		head = new Node(str,tail);
		head->setNext(ptr);
		ptr->setPrev(head);
		tail->setNext(head);
	}
	count += 1;
	return;
}
void Buffer::produceAtTail(const std::string str)
{
	if(head==NULL) // if there are no node
	{
		head = new Node(str);
		tail = head;
	}
	else
	{
		Node* ptr = tail;
		tail = new Node(str,ptr);
		tail->setNext(head);
		ptr->setNext(tail);
		head->setPrev(tail);
	}
	count += 1;
	return;
}
Iterator Buffer::produceAtMiddle(Iterator pos, const std::string str)
{
	if(head==NULL) // if there are no node
	{
		head = new Node(str);
		tail = head;
		count += 1;
		Iterator temp(head);
		return temp;
	}
	else
	{
		Node* nextPtr = pos.getCurr();
		Node* prevPtr = nextPtr->getPrev();
		Node* ptr = prevPtr->getNext();
		ptr = new Node(str,prevPtr);
		nextPtr->setPrev(ptr);
		ptr->setNext(nextPtr);
		prevPtr->setNext(ptr);
		count += 1;
		Iterator temp(ptr);
		return temp;
	}
}
void Buffer::consumeAtHead()
{
	if(count==0) return;
	Node* trash = head;
	head = trash->getNext();
	head->setPrev(tail);
	tail->setNext(head);
	delete trash;
	count -= 1;
	return;
}
void Buffer::consumeAtTail()
{
	if(count==0) return;
	Node* trash = tail;
	tail = trash->getPrev();
	head->setPrev(tail);
	tail->setNext(head);
	delete trash;
	count -= 1;
	return;
}
void Buffer::consume(Iterator it)
{
	if(count==0) return;
	Node* trash = it.getCurr();
	Node* prevPtr = trash->getPrev();
	Node* nextPtr = trash->getNext();
	prevPtr->setNext(nextPtr);
	nextPtr->setPrev(prevPtr);
	delete trash;
	count -= 1;
	return;
}
void Buffer::consume(Iterator s, Iterator t)
{
	if(count==0) return;
	Node* onePtr = s.getCurr();
	Node* otherPtr = t.getCurr();
	while(onePtr != otherPtr)
	{
		Node* trash = onePtr;
		Node* prevPtr = trash->getPrev();
		Node* nextPtr = trash->getNext();
		onePtr = onePtr->getNext();
		delete trash;
		count -= 1;
	}
	return;
}
unsigned Buffer::size() const
{
	return count;
}
bool Buffer::isEmpty()
{
	if(count == 0)
		return true;
	else return false;
}
std::string& Buffer::operator[](int i) const
{
	Node* ptr = head;
	for(int index=0; index<i; index++)
	{
		ptr = ptr->getNext();
	}
	return ptr->getWord();
}
Iterator Buffer::getHeadItr()
{
	Iterator temp(head);
	return temp;
}
Iterator Buffer::getTailItr()
{
	Iterator temp(tail);
	return temp;
}
Iterator Buffer::getNextItr(Iterator it)
{
	Node* curr = it.getCurr();
	Iterator temp(curr->getNext());
	return temp;
}
Iterator Buffer::getPrevItr(Iterator it)
{
	Node* curr = it.getCurr();
	Iterator temp(curr->getPrev());
	return temp;
}
void Buffer::print()
{
	if(count==0)
	{
		cout << "->";
	}
	else if(count==1)
	{
		cout << head->getWord() << " -> ";
	}
	else
	{
		Node* ptr = head;
		while(1)
		{
			cout << ptr->getWord();
			if(ptr == tail) break;
			cout << " -> ";
			ptr = ptr->getNext();
		}
	}
	cout << endl;
	cout << endl;
	return;
}

// private functions
// 	: deep copy for copy constructor
void Buffer::copy(const Buffer& other)
{
	Node* copyPtr = other.head;
	Node* ptr = head;
	Node* prevPtr = ptr;
	while(1)
	{
		if(head == NULL)
		{
			head = new Node(copyPtr->getWord(),head);
			head->setNext(head);
			tail = ptr;
		}
		else
		{
			ptr = new Node(copyPtr->getWord(),prevPtr);
			tail = ptr;
			ptr->setNext(head);
		}
		if(copyPtr == other.tail) break;
		prevPtr = ptr;
		ptr = ptr->getNext();
		copyPtr = copyPtr->getNext();
	}
	head->setPrev(tail);
}
void Buffer::clear()
{
	deleteBuffer(tail);
	return;
}
void Buffer::deleteBuffer(Node* p)
{
	Node* trash = p;
	p = p->getPrev();
	delete trash;
	if(p != head) deleteBuffer(p);
}

// non-member function
bool findNode(Iterator first, Iterator last, std::string str)
{
	Node* findPtr = first.getCurr();
	while(findPtr != last.getCurr())
	{
		if(findPtr->getWord() == str) return 1;
		findPtr = findPtr->getNext();
	}
	return 0;
}
