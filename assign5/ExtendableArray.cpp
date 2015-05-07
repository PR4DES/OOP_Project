// CSE24102 OOP[Assign5, 20141435, Song-ei Lee]
#include "ExtendableArray.h"
//
// ElementRef Class : reference of the element
//
// constructor
ElementRef::ElementRef(ExtendableArray& theArray, int i) {
	index = i;
	intArrayRef = &theArray;
}
// copy constructor
ElementRef::ElementRef(const ElementRef& other) {
	index = other.index;
	intArrayRef = other.intArrayRef;
}
// destructor
ElementRef::~ElementRef() {
}
// overloading operator = : assign ElementRef.
// using operator = of int parameter
ElementRef& ElementRef::operator=(const ElementRef& rhs) {
	if (rhs.index < rhs.intArrayRef->size) {
		int val = rhs.intArrayRef->arrayPointer[rhs.index];
		*this = val;
	} else {
		*this = 0;
	}
	return *this;
}
// overloading operator = : assign int.
// two cases
// 1. array subscript is larger than available memory size. (if value is 0 and it is assigned into the index larger than size, not extended)
// 	-> copy and remove the original one.
// 	-> remake array pointed by arrayPointer which has index+1 size.
// 	-> fill the new array. (copy + 0 + value)
// 2. not the first case.
// 	-> put the value into the correct position.
ElementRef& ElementRef::operator=(int val) {
	if(index>intArrayRef->size-1) {
		if(val!=0) {
			int *temp;
			temp = new int[intArrayRef->size];
			for(int i=0; i<intArrayRef->size;i++)
				temp[i] = intArrayRef->arrayPointer[i];
			delete[] intArrayRef->arrayPointer;
			intArrayRef->arrayPointer = new int[index+1];
			for(int i=0; i<intArrayRef->size; i++)
				intArrayRef->arrayPointer[i] = temp[i];
			delete[] temp;
			for(int i=intArrayRef->size; i<index; i++)
				intArrayRef->arrayPointer[i] = 0;
			intArrayRef->arrayPointer[index] = val;
			intArrayRef->size = index+1;
		}
	}
	else
		intArrayRef->arrayPointer[index] = val;
	return *this;
}
// convert the object to an integer if needed.
// if the program want to the element which has the size less than the index.
ElementRef::operator int() const {
	if(index>intArrayRef->size-1)
		return 0;
	return intArrayRef->arrayPointer[index];
}

//
// ExtendableArray Class
//
// constructor : initialize the size to 2, and all element of the arrayPointer to 0.
ExtendableArray::ExtendableArray() {
	size = 2;
	arrayPointer = new int[size];
	for(int i=0; i<size; i++)
		arrayPointer[i] = 0;
}
// copy constructor
ExtendableArray::ExtendableArray(const ExtendableArray& other) {
	size = other.size;
	arrayPointer = new int[size];
	for(int i=0; i<size; i++)
		arrayPointer[i] = other.arrayPointer[i];
}
// destructor
ExtendableArray::~ExtendableArray() {
	if(size>0)
		delete[] arrayPointer;
}
// overloading operator = : this function is used
// 1. when assign object of ExtendableArray class to another object
// 2. when the object is passed as parameter.
ExtendableArray& ExtendableArray::operator=(const ExtendableArray& rhs) {
	size = rhs.size;
	delete[] arrayPointer;
	arrayPointer = new int[size];
	for(int i=0; i<size; i++)
		arrayPointer[i] = rhs.arrayPointer[i];
	return *this;
}
// overloading operator []
// return the object of ElementRef
ElementRef ExtendableArray::operator[](int i) {
	ElementRef r(*this,i);
	return r;
}
