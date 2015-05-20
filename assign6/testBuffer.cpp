// testBuffer.cpp

#include "Buffer.h"
#include "Iterator.h"
#include<iostream>
using namespace std;

int main()
{
	Buffer test; // test default constructor
	test.produceAtHead("Manners"); // test produceAtHead()
	test.produceAtTail("Man"); // test produceAtTail()

	Iterator testItHead = test.getHeadItr(); // test getHeadItr()
	Iterator testItNextHead = test.getNextItr(testItHead); // test getNextItr()

	test.produceAtMiddle(testItNextHead, "Maketh"); // test produceAtMiddle()
	test.print(); // Manners -> Maketh -> Man

	cout << test[1] << endl; // Maketh
	if(!test.isEmpty()) // test isEmpty()
	{
		cout << "Size of test : " << test.size() << endl; // 3
	}

	cout << "Head element of test : " << test.getHeadElement() << endl;
	cout << "Tail element of test : " << test.getTailElement() << endl;
}
