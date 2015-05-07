// CSE24102 OOP[Assign4/20141435] Song-ei Lee
//
// IntArray class: Feel free to add additional member functions to this class
//
#include<iostream>
#include<cstdlib>
using namespace std;
class IntArray{
	private:
		int nelements;
		int *elements;
	public:
		IntArray();
		IntArray(IntArray &);
		int pop();
		bool empty() const;
		int top() const;
		void push(int);
		int& operator[](int);
		void operator=(const IntArray &);
		void appendCopyAtEnd(const IntArray&);
		friend ostream& operator<<(ostream& os, const IntArray& arg){
			for (int i=0;i<arg.nelements;i++) {
				os << arg.elements[i] << ' ';
			}
			return os;
		}
		~IntArray();
};
// Constructor : initialize nelements and elements
IntArray::IntArray(){
	nelements=0;
	elements = new int[nelements];
}
// Copy Constructor : copy the content of IntArray variable into another IntArray variable
IntArray::IntArray(IntArray &obj){
	nelements = obj.nelements;
	elements = new int[nelements];
	for(int i=0; i<nelements; i++)
		elements[i] = obj.elements[i];
}
// pop function : remove elements[0] and move the other elements to front position.
//		  return the value removed that was elements[0].
int IntArray::pop() {
	int ReturnValue;
	int *temp;
	temp = new int[nelements];
	for(int i=0; i<nelements; i++)
		temp[i] = elements[i];
	ReturnValue = elements[0];
	nelements -= 1;
	delete[] elements;
	elements = new int[nelements];
	for(int i=0; i<nelements; i++)
		elements[i] = temp[i+1];
	delete[] temp;
	return ReturnValue;
}
// empty function : if there are no elements, it return true. otherwise, false.
//		    (number of elements is zero)
bool IntArray::empty() const {
	if(nelements == 0)
		return true;
	else return false;
}
// top function : if top is called on an empty list, print error message and exit the program.
// 		  if not, return first element.
int IntArray::top() const {
	if(nelements==0) {
	cout << "Error: invalid memory access" << endl; 
	exit(1);
	}
	return *elements;
}
// push function : push elements and add new element.
// 		   1. make temp and store content of original elements.
//		   2. delete original elements and make elements that can store one integer more than original one.
// 		   3. move the content of temp to next room of elements and add the new integer into first element.
void IntArray::push(int NewNum) {
	int *temp;
	temp = new int[nelements];
	for(int i=0; i<nelements; i++)
		temp[i] = elements[i];
	nelements += 1;
	delete[] elements;
	elements = new int[nelements];
	for(int i=0; i<nelements-1; i++)
		elements[i+1] = temp[i];
	elements[0] = NewNum;
	delete[] temp;
	return;
}
// operator[] function : if it is called with out of bound index, it print error message and exit the program.
// 			 if not, it return the element that is called.
int& IntArray::operator[](int i) {
	if(nelements-1<i) {
		cout << "Error: invalid memory access" << endl;
		exit(1);
	}
	return elements[i];
}
// operator= function : copy the right hand side to left hand side.
void IntArray::operator=(const IntArray &obj) {
	nelements = obj.nelements;
	elements = new int[nelements];
	for(int i=0; i<nelements; i++)
		elements[i] = obj.elements[i];
	return;
}
// appendCopyAtEnd : append the copy of one IntArray variable at the end of another IntArray variable.
void IntArray::appendCopyAtEnd(const IntArray& obj) {
	int *temp;
	temp = new int[nelements];
	for(int i=0; i<nelements; i++)
		temp[i] = elements[i];
	delete[] elements;
	elements = new int[nelements+obj.nelements];
	for(int i=0; i<nelements+obj.nelements; i++) {
		if(i<nelements)
			elements[i] = temp[i];
		else elements[i] = obj.elements[i-nelements];
	}
	nelements += obj.nelements;
	delete[] temp;
	return;
}
// destructor : delete elements after the processing.
IntArray::~IntArray() {
	delete[] elements;
}
