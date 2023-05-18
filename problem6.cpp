/*
You are given two positive integers A and B. Find the number of pairs of positive integers (X,Y) such that 1≤X≤A, 1≤Y≤B and X+Y is even.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.
Output
For each test case, print a single line containing one integer ― the number of valid pairs.

Constraints
1≤T≤1,000
1≤A,B≤109

*/
#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    long long x, y;
    for(int i=1;i<=N;++i) {
        cin >> x >> y;
        cout <<  (x/2)*(y/2) + (x-(x/2)) * (y - (y/2)) << endl;
    }
    return 0;
}