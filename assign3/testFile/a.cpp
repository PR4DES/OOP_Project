#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	string black[5], white[5];
	while(1) {
		if(cin.eof()) break;
		for(int i=0; i<10; i++) {
			cin >> input;
			if(i<5) black[i]=input;
			else white[i-5]=input;
		}
	}
	cout << endl;
}
