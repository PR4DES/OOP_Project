#include<iostream>
using namespace std;

class IntArray {
	private :
		int nelements;
		int *elements;
	public :
		IntArray();
		int& operator[](int);
		friend ostream& operator<<(ostream& os, const IntArray& arg) {
			for(int i=0; i<arg.nelements; i++)  {
				os << arg.elements[i] << ' ';
			}
		return os;
		}
};
IntArray::IntArra(){
	nelements = 0;
}
int IntArray::operator[](int i) {
}
int main() {
	IntArray s1;
	for(int i=0; i<10; i++)
		s1[i] = i;
	cout << s1 << endl;
	s1[100] = 100;
	return 0;
}
