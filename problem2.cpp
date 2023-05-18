/* There are two groups, one of N boys and the other of N girls numbered from 1 to N.

You are given two arrays A and B containing N numbers each, denoting the height of boys and girls in the group. You have to form N couples, where each couple will consist of 1 boy and 1 girl.

Each couple has a LIKENESS VALUE, where

LIKENESS VALUE = height of girl in the couple + height of boy in that couple.
You have to form N couples in such a way that the maximum of LIKENESS VALUE of all the couples is minimum.

Note:- No boy or girl can form more than one couple.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N:- number of boys and number of girls in the group.
The second line of each test case contains N space-separated integers, denoting the height of N boys.
The third line of each test case contains N space-separated integers, denoting the height of N girls.
Output
For each test case, print the maximum LIKENESS VALUE in a new line.
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int T; // no of test cases

    cin >> T;

    for(int i =1;i<=T;++i) {
        cin >> n;
        vector<int> boys, girls;
        int h;

        for(int i=0;i<n;++i) {
            cin >> h;
            boys.push_back(h);
        }

        for(int i=0;i<n;++i){
            cin >> h;
            girls.push_back(h);
        }

        sort(boys.begin(),boys.end());
        sort(girls.begin(),girls.end());
        int large = INT_MIN;
        for(int i=0;i<n;++i) {
            large = max(large,boys[i] + girls[n-i-1]);
        }
        cout << large << endl;
    }
}