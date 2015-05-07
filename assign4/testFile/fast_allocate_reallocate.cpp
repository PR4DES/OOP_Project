#include "IntArray.h"
#include <iostream>
#define TEST_SIZE 2000
using namespace std;

int main() {
        cout << "For me, with TEST_SIZE = 2000, it takes around 3 minutes in uni0x server." << endl;
        cout << "If it takes too long to finish or get killed, then there's should be a problem (or problems)." << endl;
        cout << "Fast allocate-reallocate" << endl;
        IntArray s1, s2, s3;
        for (int j = 0; j < TEST_SIZE; j++) {
                s1 = s3;
                s2 = s3;
                for (int i = 0; i < 2 * TEST_SIZE; i++) {
                        s1.push(2*i);
                }
                for (int i = 0; i < TEST_SIZE; i++) {
                        s2.push(3*i);
                }
                s2 = s1;
        }
        cout << "In reverse order" << endl;
        for (int j = 0; j < TEST_SIZE; j++) {
                s1 = s3;
                s2 = s3;
                for (int i = 0; i < 2 * TEST_SIZE; i++) {
                        s1.push(2*i);
                }
                for (int i = 0; i < TEST_SIZE; i++) {
                        s2.push(3*i);
                }
                s1 = s2;
        }
}
