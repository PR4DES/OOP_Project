//
// IntArray class: Feel free to add additional member functions to this class
//
#include<iostream>
using namespace std;
class IntArray{
	private:
		int nelements;
		int *elements;
	public:
		IntArray();
		IntArray(IntArray *);
		int pop();
		bool empty() const;
		int top() const;
		void push(int);
		int& operator[](int);
		void appendCopyAtEnd(const IntArray&);
		friend ostream& operator<<(ostream& os, const IntArray& arg){
			for (int i=0;i<arg.nelements;i++) {
				os << arg.elements[i] << ' ';
			}
			return os;
		}
		~IntArray();
};
IntArray::IntArray(){
	nelements=0;
	elements = new int[nelements];
}
IntArray::IntArray(IntArray *obj){
	nelements = obj->nelements;
	elements = new int[nelements];
	for(int i=0; i<nelements; i++)
		elements[i] = obj->elements[i];
}
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
bool IntArray::empty() const {
	if(nelements == 0)
		return true;
	else return false;
}
int IntArray::top() const {
	return *elements;
}
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
int& IntArray::operator[](int i) {
	if(nelements>i)
		return elements[i];
	else cout << "Error: invalid memory access" << endl;
}
void IntArray::appendCopyAtEnd(const IntArray& obj) {
	nelements += obj.nelements;
	delete[] elements;
	elements = new int[nelements];
	for(int i=nelements-obj.nelements; i<nelements; i++) {
		elements[i] = obj.elements[i+obj.nelements-nelements];
	}
	return;
}
IntArray::~IntArray() {
	delete[] elements;
}
