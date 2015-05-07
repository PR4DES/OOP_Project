//CSE24102 [OOP]Assign3-20141435 Song-ei Lee
#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	while(1) {
		string valueB[5], valueW[5];
		string suitB[5], suitW[5];
		if(cin.eof()) break;
		getline(cin,input);
		for(int a=0; a<input.length(); a++) {
			if(input[a]=='C' || input[a]=='D' || input[a]=='H' || input[a]=='S') {
				for(int b=0; b<5; b++) {
					if(suitB[b]=="") suitB[b] = input[a];
					else if(suitB[4]!="" && suitW[b]=="") suitW[b] = input[a];
				}
			}
			else if(input[a]!="") {
				if(input[a]=="A") input[a] = '1';
				else if(input[a]=="T") input[a] = '10';
				else if(input[a]=="J") input[a] = '11';
				else if(input[a]=="Q") input[a] = '12';
				else if(input[a]=="K") input[a] = '13';
				for(int b=0; b<5; b++) {
					if(valueB[b]=="") valueB[b] = input[a];
					else if(valueB[4]!="" && valueW[b]=="") valueW[b] = input[a];
				}
			}
		}
		for(int i=0; i<5; i++) {
			cout << "i " << i << endl;
			cout << "valueB " << valueB[i] << endl;
			cout << "valueW " << valueW[i] << endl;
			cout << "suitB " << suitB[i] << endl;
			cout << "suitW " << suitW[i] << endl;
		}
	// High Card : 1, Pair : 2, ... , Straight Flush : 9
	}
	return 0;
}
