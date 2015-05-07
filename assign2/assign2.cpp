//CSE24102 20141435 Song-ei Lee
#include<iostream>
#include<string>
using namespace std;

void processing();

int main() {
	int numofCase;
	cin >> numofCase;
	cin.ignore();
	// repeat number of case times
	for(int i=0; i<numofCase; i++){
		processing();
		if(i != numofCase-1) cout << endl;
	}
	return 0;
}

void processing() {
	int numofLine;
	string inputLine[100];
	string plaintext = "the quick brown fox jumps over the lazy dog";
	if(cin.peek()=='\n') cin.ignore();
	// find number of lines
	for(int a=0; a<100; a++) {
		getline(cin,inputLine[a]);
		if(inputLine[a]=="") {numofLine = a; break;}
	}
	// enc[] : encrypted lines(input)
	// sen[] : decrypted lines(output)
	string enc[numofLine], sen[numofLine];
	for(int a=0; a<numofLine; a++)
		enc[a] = inputLine[a];
	// No solution case
	// 1. there are no line which has same length to plaintext
	// 2. the line which has same length to plaintext, but there are absent alphabet
	int count=0;
	int plaintextLine;
	for(int a=0; a<numofLine; a++) {
		if(enc[a].length() == plaintext.length()) {
			for(char b='a'; b<='z'; b++)
				for(int c=0; c<enc[a].length(); c++)
					if(b==enc[a][c]) {count++; break;}
			if(count == 26) {plaintextLine = a; break;}
			else if(a == numofLine-1) {
				cout << "No solution." << endl; // No solution case 1
				return;
			}
		} else if(a == numofLine-1) {
				cout << "No solution." << endl; // No solution case 2
				return;
		}
	}
	// make a key set and initialize it
	char key[26];
	for(int a=0; a<26; a++)
		key[a] = 'a'+a;
	// comparing the plaintext to encrypted text, find the key
	for(int a=0; a<26; a++) {
		for(int b=0; b<plaintext.length(); b++) {
			if(key[a] == plaintext[b]) { key[a] = enc[plaintextLine][b]; break;}
		}
	}
	// using the key set, find the original sentence(output)
	for(int a=0; a<numofLine; a++) {
		for(int b=0; b<enc[a].length(); b++) {
			for(int c=0; c<26; c++) {
				if(enc[a][b] == ' ') {sen[a] += ' '; break;}
				if(enc[a][b] == key[c]) sen[a] += char(c+97);
			}
		}
	}
	// display it
	for(int a=0; a<numofLine; a++) {
		cout << sen[a] << endl;
	}
	return;
}
