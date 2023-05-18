/*
For a positive, even integer N, we call a pair of arrays A and B to be interesting if they satisfy the following conditions :

|A|=|B|=N/2 i.e. the length of array A is equal to the length of array B.

Each integer from 1 to N occurs exactly once in exactly one of the arrays.

The ith prefix sum of A is not equal to ith prefix sum of B for all 1≤i≤N/2−1. Formally, ∑j=1iAj≠∑j=1iBj for all 1≤i≤N/2−1
Sum of all elements in A is equal to sum of all elements in B i.e. ∑j=1N/2Aj=∑j=1N/2Bj
You are given a positive, even integer N. If there exists an interesting pair of arrays, then print "YES" followed by an interesting pair for this given N.
 If there exists multiple interesting pairs of arrays for given N, you can print any. Print "NO" in a single line if no such pair exists.
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;  // no of test cases

    int n;
    for(int i=1;i<=T;++i) {
        cin >> n;
        if(n % 4 != 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            int a = n >> 2;
            for(int i=a+1;i<=3*a;++i) {
                cout << i << ' ';
            }
            cout << endl;
            for(int i=1;i<=a;++i) {
                cout << i << ' ';
            }
            for(int i=1;i<=a;++i) {
                cout << 3*a + i << ' ';
            }
            cout << endl;
        }

    }
}