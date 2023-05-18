/* GREAT PROBLEM -> ONLY 7 TEAMS SOLVED
You are given a complete graph of N nodes. You have to color each edge of this graph using one of the K given colors. Colors are numbered from 1 to K.

Let's denote d_j as the diameter of the graph formed using these N nodes and edges of color j.
The value of d_j must be less than or equal to 4 for each color.
Note: In a graph, if there does not exist a path between two nodes, the distance between them can be assumed to be infinity.

Input format
The first line contains T, the number of testcases.
Each of the next T lines contains two integers N and K.
Constraints
2 ≤ N ≤ 100
1 ≤ K ≤ N * (N - 1) / 2
1 ≤ Sum of N over all testcases ≤ 10,000
Output format
For each testcase:
The first line should contain a string YES or NO. Print NO if coloring is impossible and YES otherwise.
If the answer is YES, print N - 1 more lines, ith line should have i integers, where the jth integer on the ith line should contain the color of the edge from node j to node i + 1.
Sample 0
Input
2
5 10
5 2
Output
NO
YES
1
2 1
2 2 1
1 2 2 1
Explanation
In the first example, it can be proven that its impossible to add such coloring.
In the second example, one such coloring is shown below. Blue is color 1, and Yellow is color 2.
*/


#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n, k; cin >> n >> k;
	if (k <= (n/2)) {
		cout << "YES\n";
	} else {
		cout << "NO\n"; return ;
	}
	
	vector<int> types(n+1,-1);
	int t=1;
	for(int i=1;i<=n;++i) {
		if (i % k == 0) { types[i] = t; if (t <= 2) ++t;}
		else {types[i] = t;}
	}
	
	for(int i=2;i<=n;++i) {
		for(int j=1;j<i;++j) {
			if (types[i] == 1) cout << max((i-1)%k, (j-1)%k) + 1 << ' ';
			else if (types[i] == 2) {
				if (types[j] == 1) {
					cout << min((i-1)%k, (j-1)%k) + 1 << ' ';
				} else {
					cout << max((i-1)%k, (j-1)%k) + 1 << ' ';
				}
			} else {
				if (types[j] <= 2) {
					cout << (j-1)%k + 1 << ' ';
				} else {
					cout << 1 << ' ';
				}
			}
		}
		cout << '\n';
	}
}

int32_t main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}