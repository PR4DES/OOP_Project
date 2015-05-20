// testNode.cpp

#include "Node.h"
#include<iostream>
using namespace std;

int main()
{
	Node test1; // test default constructor
	Node test2("test2Word"); // test Copy constructor with 1 argument
	Node* test3 = new Node("test3Word");
	Node test4("test4Word", test3); // test Copy constructor with 2 argument

	test1.setWord("test1Word"); // test setWord()
	test2.setNext(test3); // test setNext()
	test3->setPrev(test3); // test setPrev()

	/*
	NULL <-(prev) test1 (next)-> NULL
	test2(next) -> test3 <-(prev) test4
			^ |
			| | (prev)
			---
	*/

	// test getWord()
	cout << "test1 word : " << test1.getWord() << endl; // test1Word
	cout << "test2 word : " << test2.getWord() << endl; // test2Word
	cout << "test3 word : " << test3->getWord() << endl; // test3Word
	cout << "test4 word : " << test4.getWord() << endl; // test4Word

	// test getNext()
	cout << "test2 next word : " << (test2.getNext())->getWord() << endl; // test3Word
	// test getPrev()
	cout << "test3 prev word : " << (test3->getPrev())->getWord() << endl; // test3Word
	cout << "test4 prev word : " << (test4.getPrev())->getWord() << endl; // test3Word
	delete test3;
}
