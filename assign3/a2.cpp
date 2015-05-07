// [OOP]Assign3 CSE24102 20141435 Song-ei Lee
#include<iostream>
#include<string>
using namespace std;

string ATJQKtoNum(string);
void rearrangeValues(int*);
int analysis(int*, string);
void scoreCompare(int*, int*, int);

// The program : determining who is winner in poker games.
// Three steps 1. Input 2. Rearrangement 3. analysis 4. Comparing
// 1. Input : In main function, divide input line into black card and white card. Then again divide cards into value and suit
// 2. Rearrangement : Frist in ATJQKtoNum function, change the char value such as A,T to int value. Then in rearrangeValues function, rearrange values from low value to high value
// 3. Analysis : In analysis function, using the values and suits, determine the scores.
// 4. Comparing : Then if the score is same, in scoreCompare function, finally determine the last winner(or tie).
int main() {
	string input;
	string temp;
	while(1) {
		if(cin.eof()) break; // if input file ends, it stops.
		string black[5], white[5];
		for(int i=0; i<10; i++) {
			cin >> input;
			if(i<5) black[i]=input;
			else white[i-5]=input;
		}
		if(black[0]==black[1]) break; // remove error line
		int valueB[5]={0}, valueW[5]={0};
		string suitB, suitW;
		for(int i=0; i<5; i++) {
			temp=black[i][0];
			valueB[i] = atoi(ATJQKtoNum(temp).c_str());
			temp=white[i][0];
			valueW[i] = atoi(ATJQKtoNum(temp).c_str());
			suitB += black[i][1];
			suitW += white[i][1];
		}
		rearrangeValues(valueB);
		rearrangeValues(valueW);
		int scoreB=analysis(valueB,suitB);
		int scoreW=analysis(valueW,suitW);
		if(scoreB>scoreW) cout << "Black wins." << endl;
		else if(scoreB<scoreW) cout << "White wins." << endl;
		else
			scoreCompare(valueB, valueW, scoreB);
	}
	return 0;
}
// the character number is difficult to treat, so change it into the number
string ATJQKtoNum(string temp){
	if(temp=="A") temp="14";
	else if(temp=="T") temp="10";
	else if(temp=="J") temp="11";
	else if(temp=="Q") temp="12";
	else if(temp=="K") temp="13";

	return temp;
}
// rearrangement of values to make comparing easy
void rearrangeValues(int* value) {
	int l=0;
	for(int j=0; j<5; j++)
		for(int i=0; i<4; i++)
			if(value[i]>value[i+1]) {
				l = value[i+1];
				value[i+1] = value[i];
				value[i] = l;
			}
}
// anaysis the card and determining its score
// score 1 == High Card, score 2 == Pair, ... , score 9 == Straight Flush (low to high)
int analysis(int* value, string suit) {
	int score=0;
	if(value[0]+1==value[1] && value[1]+1==value[2] && value[2]+1==value[3] && value[3]+1==value[4]) {
		if(suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4]) score=9;
		else score=5;
	} else {
		if(value[0]==value[1]) {
			if(value[1]==value[2]) {
				if(value[2]==value[3]) score=8;
				else if(value[3]==value[4]) score=7;
				else score=4;
			} else {
				if(value[2]==value[3]) {
					if(value[3]==value[4]) score=7;
					else score=3;
				} else if(value[3]==value[4]) score=3;
				else score=2;
			}
		} else if(value[1]==value[2]) {
			if(value[2]==value[3]) {
				if(value[3]==value[4]) score=8;
				else score=4;
			} else if(value[3]==value[4]) score=3;
			else score=2;
		} else if(value[2]==value[3]) {
			if(value[3]==value[4]) score=4;
			else score=2;
		} else if(value[3]==value[4]) score=2;
		else score=1;
	} 
	if(suit[0]==suit[1] && suit[1]==suit[2] && suit[2]==suit[3] && suit[3]==suit[4])
		if(score<6) score=6;

	return score;
}
// comparing the score when their score is same by case of score
void scoreCompare(int* valueB, int* valueW, int score) {
	if(score==1||score==6) {
		for(int i=4; i>=0; i--) {
			if(valueB[i]>valueW[i]) { cout << "Black wins." << endl; break; }
			else if(valueB[i]<valueW[i]) { cout << "White wins." << endl; break; }
			else if(i==0) cout << "Tie." << endl;
		}
	} else if(score==5||score==9) {
		if(valueB[4]>valueW[4]) cout << "Black wins." << endl;
		else if(valueB[4]<valueW[4]) cout << "White wins." << endl;
		else cout << "Tie." << endl;
	} else if(score==2||score==8||score==4||score==3){
		for(int i=4; i>0; i--) 
			if(valueB[i]==valueB[i-1])
				for(int j=4; j>0; j--)
					if(valueW[j]==valueW[j-1]) {
						if(valueB[i]>valueW[j]) cout << "Black wins." << endl;
						else if(valueB[i]<valueW[j]) cout << "White wins." << endl;
						else {
							if(score==2||score==4) scoreCompare(valueB,valueW,1);
							else if(score==3) {
								for(int a=0; a<3; a++)
									if(valueB[a]==valueB[a+1])
										for(int b=0; b<3; b++)
											if(valueW[b]==valueW[b+1]) {
												if(valueB[a]>valueW[b]) cout << "Black wins." << endl;
												else if(valueB[a]<valueW[b]) cout << "White wins." << endl;
												else {
													int tempB, tempW;
													if(valueB[0]!=valueB[1]) tempB=valueB[0];
													else if(valueB[2]!=valueB[3]) tempB=valueB[2];
													else tempB=valueB[4];
													if(valueW[0]!=valueW[1]) tempW=valueW[0];
													else if(valueW[2]!=valueW[3]) tempW=valueW[2];
													else tempW=valueW[4];
													if(tempB>tempW) cout << "Black wins." << endl;
													else if(tempB<tempW) cout << "White wins." << endl;
													else cout << "Tie" << endl;
												}
											}
							} else{
								if(i==j) {
									if(i=3) i=4; else if(i=4) i=0;
									if(valueB[i]>valueW[i]) cout << "Black wins." << endl;
									else if(valueB[i]<valueW[i]) cout << "White wins." << endl;
									else cout << "Tie." << endl;
								}
								else if(i>j) cout << "White wins." << endl;
								else cout << "Black wins." << endl;
							}
						}
						return;
					}
	} else {
		for(int i=4; i>1; i--)
			if(valueB[i]==valueB[i-1] && valueB[i-1]==valueB[i-2]) {
				for(int j=4; j>1; j--)
					if(valueW[j]==valueW[j-1] && valueW[j-1]==valueW[j-2]) {
						if(valueB[i]>valueW[j]) cout << "Black wins." << endl;
						else if(valueB[i]<valueW[j]) cout << "White wins." << endl;
						else {
							if(i<j) cout << "Black wins." << endl;
							else if(i>j) cout << "White wins." << endl;
							else {
								if(i==4) {
									if(valueB[0]==valueW[0]) cout << "Tie." << endl;
									else if(valueB[0]>valueW[0]) cout << "Black wins." << endl;
									else cout << "White wins." << endl;
								} else {
									if(valueB[4]==valueW[4]) cout << "Tie." << endl;
									else if(valueB[4]>valueW[4]) cout << "Black wins." << endl;
									else cout << "White wins." << endl;
								}
							}
						}
						return;
					}
			}
	}
	return;
}
