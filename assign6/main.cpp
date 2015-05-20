// main.cpp
//	g++ main.cpp Buffer.cpp Node.cpp Iterator.cpp

#include <iostream>
#include "Buffer.h"
#include "Iterator.h"

using namespace std;

int main() {
  Buffer v1;
  Iterator it;

  v1.produceAtHead("Is");
  v1.produceAtHead("Name");
  v1.produceAtHead("My");
  v1.produceAtTail("James");
  v1.produceAtTail("Bond");

  cout << "count = " << v1.size() << endl; // print "5"
  cout << "first string= " << v1.getHeadElement() << endl; // print "My"
  cout << "last string= " << v1.getTailElement() << endl;  // print "Bond"
  v1.print(); // My -> Name -> Is -> James -> Bond

  v1.consumeAtHead();
  v1.consumeAtTail();
  v1.print(); // Name -> Is -> James 

  it = v1.getHeadItr();
  it = v1.getNextItr(it);
  v1.consume(it);
  v1.print(); // Name -> James


  // insert in middle
  it = v1.getTailItr();
  it = v1.produceAtMiddle(it, "Porter");
  v1.print(); // Name -> Porter -> James

  // test find
  cout << findNode(v1.getHeadItr(), v1.getTailItr(), "Bond") << endl;

  // empty buffe
  v1.consumeAtHead();
  v1.consumeAtHead();
  v1.consumeAtHead();
  cout << "count = " << v1.size() << endl; // 0
  v1.print(); // ->

  // test isEmpty()
  if (v1.isEmpty())
    cout << "empty buffer" << endl;

  return 0;
}
