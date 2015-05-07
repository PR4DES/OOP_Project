#include<iostream>
#include<string>
using namespace std;

int main() {
	int a;
	cin >> a;
	cin.ignore();
	for(int i=0; i<a; i++) {
		if(cin.peek()=='\n') cin.ignore();
		while(1) {
			string str;
			getline(cin, str);
			cout << "str : " << str << endl;
			if(str=="") break;
		}
		if(cin.eof()) break;
	}
}
