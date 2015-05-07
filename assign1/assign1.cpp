// CSE24102, 2014143, Song-ei Lee
#include<iostream>
#include<string>
using namespace std;

// I will find the longest front fragment and the longest back fragment,
// Then combine them (overlabing according to original file length.)
int main(){
        int numofCase;
        cin >> numofCase; // input : number of case
        string file[numofCase];
	cin.ignore();

	// comparing first fragment, categorize fragments into four category
	// category : front fragment, back fragment, unknown fragment that is same position with first one, unknown fragment that is opposite to first one.
        for(int i=0; i<numofCase; i++) {
		if(cin.peek()=='\n') cin.ignore();
		int maxFragLen=0, minFragLen=256;
		int fileLen;
		// make category
		string frontFrag[numofCase], backFrag[numofCase];
		string frag1[numofCase], frag2[numofCase];
		int row=1; // start with first row
                while(1) {
			string frag;
			getline(cin,frag);
			if(frag==""&&row!=1) break;
			if(frag1[i]=="") frag1[i] = frag; // first fragment is standard
			// finding original file's length
			// maximum fragment length + minimum fragment length
			if(maxFragLen < frag.length()) maxFragLen = frag.length();
			if(minFragLen > frag.length()) minFragLen = frag.length();
			fileLen = maxFragLen+minFragLen;
			// put the fragments each category
                        if(row>1) {
				if(frag1[i].length() > frag.length()) {
					for(int a=0; a<frag.length(); a++) {
						if(frag1[i][a]!=frag[a]) {
							for(int b=0; b<frag.length(); b++) {
								if(frag1[i][frag1[i].length()-1-b]!=frag[frag.length()-1-b]) {
									if(frag2[i].length() < frag.length()) frag2[i]=frag;
									break;
								} else if(b==frag.length()-1 && backFrag[i].length() < frag1[i].length()) backFrag[i]=frag1[i];
							}
							break;
						} else if(a==frag.length()-1 && frontFrag[i].length() < frag1[i].length()) frontFrag[i] = frag1[i];
					}
				} else {
					for(int a=0; a<frag1[i].length(); a++) {
						if(frag1[i][a]!=frag[a]) {
							for(int b=0; b<frag1[i].length(); b++) {
								if(frag1[i][frag1[i].length()-1-b]!=frag[frag.length()-1-b]) {
									if(frag2[i].length() < frag.length()) frag2[i] = frag;
									break;
								} else if(b==frag1[i].length()-1 && backFrag[i].length() < frag.length()) backFrag[i] = frag;
						}
							break;
						} else if(a==frag1[i].length()-1 && frontFrag[i].length() < frag.length()) frontFrag[i] = frag;
					}
				}
			}
			if(cin.eof()) break;
			row++; // next row!
                }
		// If one of front and back fragment or both are empty,
		// we should determine whether frag1 is front fragment or back fragment.
		// because frag2 is opposite to frag1, it is determined automatically.
		if(frontFrag[i] != "" && backFrag[i] == "") {
			if(frag2[i] != "") {
				for(int a=0; a<frag1[i].length(); a++) {
					if(frontFrag[i][a] != frag1[i][a]) {
						backFrag[i] = frag1[i];
						break;
					} else if(a==frag1[i].length()-1) backFrag[i] = frag2[i];
				}
			} else backFrag[i] = frag1[i];
		} else if(frontFrag[i] == "" && backFrag[i] != "") {
			if(frag2[i] != "") {
				for(int a=0; a<frag1[i].length(); a++) {
					if(backFrag[i][backFrag[i].length()-1-a] != frag1[i][frag1[i].length()-1-a]) {
						frontFrag[i] = frag1[i];
						break;
					} else if(a==frag1[i].length()-1) frontFrag[i] = frag2[i];
				}
			} else frontFrag[i] = frag1[i];
		} else if(frontFrag[i] == "" && backFrag[i] == "") {
			frontFrag[i] = frag1[i];
			backFrag[i] = frag2[i];
		}
		// combine frontFragment and backFragment and display output
		file[i] = frontFrag[i] + backFrag[i].substr(frontFrag[i].length()+backFrag[i].length()-fileLen);
		cout << file[i] << endl;
		if(i<numofCase-1) cout << endl;
        }
        return 0;
}
