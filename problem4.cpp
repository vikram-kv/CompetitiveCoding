/*
Chef's favorite game is chess. Today, he invented a new piece and wants to see its strengths.

From a cell (X,Y), the new piece can move to any cell of the chessboard such that its color is different from that of (X,Y).

The new piece is currently located at cell (A,B). Chef wants to calculate the minimum number of steps required to move it to (P,Q).

Note: A chessboard is an 8×8 square board, where the cell at the intersection of the i-th row and j-th column is denoted (i,j). Cell (i,j) is colored white if i+j is even and black if i+j is odd.

Input Format
The first line of input contains a single integer T denoting the number of test cases. The description of the test cases follows.
Each test case consists of a single line of input, containing four space-separated integers A,B,P,Q.
Output Format
For each test case, output a single line containing one integer - the minimum number of moves taken by the new piece to reach (P,Q) from (A,B).

Constraints
1≤T≤5000
1≤A,B,P,Q≤8


*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int a, b, p, q;
    for(int i=1;i<=T;++i) {
        cin >> a >> b >> p >> q;
        if((a==p) && (b==q)) {
            cout << 0 << endl;
        }
        else if((a+b)%2 != (p+q)%2) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
}
