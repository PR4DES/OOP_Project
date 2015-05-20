// Node.cpp
#include "Node.h"

Node::Node()
{
	word = "";
	next = NULL;
	prev = NULL;
}
// Only used when there are no Node
Node::Node(std::string str)
{
	word = str;
	next = this;
	prev = this;
}
// Should set prev in buffer.cpp
Node::Node(std::string str, Node* p)
{
	word = str;
	next = NULL;
	prev = p;
}
std::string& Node::getWord()
{
	return word;
}
Node* Node::getNext() const
{
	return next;
}
Node* Node::getPrev() const
{
	return prev;
}
void Node::setWord(std::string str)
{
	word = str;
}
void Node::setNext(Node* p)
{
	next = p;
}
void Node::setPrev(Node* p)
{
	prev = p;
}
