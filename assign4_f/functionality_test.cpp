#include "IntArray.h"
#include <iostream>
using namespace std;

void empty(IntArray& il) {
   while(!il.empty()){
        cout << il.pop() << "<-";
        cout << il << endl;
   }
}

int main() {
    IntArray s1;

    for (int i = 0; i < 20; i++) {
        s1.push(2*i);
        cout << s1 << endl;
    }

    for(int i = 0; i < 10; i++) {
        s1[i] = i;
        cout << s1 << endl;
    }
    if (s1.top() == s1[0]) cout << "good" << endl;
    else cout << "fail" << endl;

    IntArray s2(s1);
    cout << s1 << endl;
    cout << s2 << endl;
    empty(s1);
    for (int i = 0; i < 20; i++)
        s1.push(2*i);
    cout << s1 << endl;
    cout << s2 << endl;
    s1.appendCopyAtEnd(s2);
    cout << s1 << endl;
    IntArray s3, s4, s5;
    cout << s1 << endl;
    cout << s2 << endl;
    s3 = s1;
    cout << s3 << endl;
    s1 = s2;
    cout << s1 << endl; 
    s2 = s2;
    cout << s2 << endl;
    s4 = s4;
    cout << s4 << endl;
    s4 = s5;
    cout << s4 << endl;
    s1 = s4;
    cout << s1 << endl;
    s2[0] = 100;
    cout << s2 << endl;
    s2[19] = 100;
    cout << s2 << endl;
    s2[20] = 100; // print out "Error: invalid memory access" and terminate
    cout << "fail" << endl;
    cout << s2 << endl;
}
