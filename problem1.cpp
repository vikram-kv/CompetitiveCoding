/*
There's an array A consisting of N non-zero integers A1..N. A subarray of A is called alternating if any two adjacent elements in it have different signs (i.e. one of them should be negative and the other should be positive).

For each x from 1 to N, compute the length of the longest alternating subarray that starts at x - that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1.

Input
The first line of the input contains an integer T - the number of test cases.
The first line of each test case contains N.
The following line contains N space-separated integers A1..N.
Output
For each test case, output one line with N space-separated integers - the lengths of the longest alternating subarray starting at x, for each x from 1 to N.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
-109 ≤ Ai ≤ 109

*/

#include <bits/stdc++.h>
using namespace std;


void compute(vector<int> A, int n) {
    vector<int> s(n);
    s[n-1] = 1;
    for(int j=n-2;j>=0;--j) {
        s[j] = 1;
        if((A[j+1] ^ A[j]) < 0) {
            s[j] = 1 + s[j+1];
        }
    }
    for(int& v : s) {
        cout << v << ' ';
    }
    cout << endl;
}


int main() {

    int T; // no of test cases

    cin >> T;

    for(int i=1;i<=T;++i) {
        vector<int> A;
        int n;
        cin >> n;
        int x;
        for(int i=0;i<n;++i) {
            cin >> x;
            A.push_back(x);
        }
        compute(A,n);
    }
    return 0;

}