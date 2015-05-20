// Iterator.cpp
#include "Iterator.h"

Iterator::Iterator(Node* currIn)
{
	curr = currIn;
}
const std::string Iterator::operator*() const
{
	return curr->getWord();
}
Iterator& Iterator::operator++()
{
	curr = curr->getNext();
	return *this;
}
Iterator Iterator::operator++(int)
{
	Iterator temp(curr->getNext());
	return temp;
}
Iterator Iterator::operator+(const int& i)
{
	for(int index=0; index<i; index++)
	{
		curr = curr->getNext();
	}
	return *this;
}
Iterator Iterator::operator+=(const int& i)
{
	for(int index=0; index<i; index++)
	{
		curr = curr->getNext();
	}
	return *this;
}
Iterator& Iterator::operator--()
{
	curr = curr->getPrev();
	return *this;
}
Iterator Iterator::operator--(int)
{
	Iterator temp(curr->getPrev());
	return temp;
}
Iterator Iterator::operator-(const int& i)
{
	for(int index=0; index<i; index++)
	{
		curr = curr->getPrev();
	}
	return *this;
}
Iterator Iterator::operator-=(const int& i)
{
	for(int index=0; index<i; index++)
	{
		curr = curr->getPrev();
	}
	return *this;
}

bool Iterator::operator==(const Iterator& other)
{
	if(this->curr == other.curr) return 1;
	return 0;
}
bool Iterator::operator!=(const Iterator& other)
{
	if(this->curr == other.curr) return 0;
	return 1;
}
Node*& Iterator::getCurr()
{
	return curr;
}
