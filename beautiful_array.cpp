
/*

Let's call a 1-indexed array A of length N beautiful if it satisfies the following conditions:

For each 1 ≤ i ≤ N - 2, A[i] ≠ A[i+2]
For each 1 ≤ i ≤ N - 3, A[i] = A[i+3]

You are given an integer array B. In one operation you can do one of the following:

Choose two positions i, j (1 ≤ i < j ≤ N) and swap B[i] and B[j].
Choose a position i (1 ≤ i ≤ N), and replace B[i] by any integer.

What is the minimum number of operations required to make the array B beautiful?

Input Format
The first line of input contains an integer T, the number of test cases.
The following lines describe the test cases. In each test case:
The first line contains the integer N, the length of the array
The second line contains N space separated integers, B[1], B[2], ... B[N]

Constraints
1 ≤ T ≤ 200
1 ≤ N ≤ 200
1 ≤ B[i] ≤ N for all 1 ≤ i ≤ N
The sum of N over all testcases doesn't exceed 200.

Output Format
For each testcase, print the minimum number of operations required to make the array beautiful on a new line.


Sample
Input
4
2
1 2
3
1 3 1
4
1 1 1 1
8
3 1 4 8 2 2 2 1


Output
0
1
2
4

Explanation
In the first testcase, the array is already beautiful.
In the second testcase, you can swap the values at positions 2 and 3 to get 1 1 3, which is a beautiful array.
In the third testcase, you can replace the value at positions 2 and 3 by 2 to get 1 2 2 1, which is a beautiful array

*/



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

void solve() {
    int n;

    cin >> n;

    vector<int> b(n+1);
    for(int i=1;i<=n;++i) {
        cin >> b[i];
    }

    vector<vector<int>> cnt(n+4, vector<int>(4,0));

    for(int i=1;i<=n;++i) {
        cnt[b[i]][(i%3 == 0) ? (3) : (i%3)]++;
    }

    if (n <= 2) {
        cout << "0\n"; return ;
    }

    if (n == 3) {
        if (b[1] != b[3]) {
            cout << "0\n"; return ;
        } else {
            cout << "1\n"; return ;
        }
    }

    if (n == 4) {
        int ans = 20000;
        for(int a=1;a<=n;++a) {
            for(int b=1;b<=n;++b) {
                for(int c=1;c<=n;++c) {
                    if (a == b or a == c) continue;
                    int cur = n - cnt[a][1] - cnt[b][2] - cnt[c][3];

                    int ab = min(cnt[b][1], cnt[a][2]);
                    int bc = min(cnt[c][2], cnt[b][3]);
                    int ac = min(cnt[c][1], cnt[a][3]);

                    if (b == c) bc = 0;
                    cur -= (ab+bc+ac);
                    
                    ans = min(cur, ans);
                }
            }
        }
        cout << ans << '\n';
        return ;
    }
    assert(n >= 5);

    int ans = 20000;
    for(int a=1;a<=n+3;++a) {
        for(int b=1;b<=n+3;++b) {
            for(int c=1;c<=n+3;++c) {
                if (a == b or b == c or c == a) continue;
                vector<int> va(3), vb(3), vc(3);
                
                for(int i=0;i<3;++i) {
                    va[i] = cnt[a][i+1];
                    vb[i] = cnt[b][i+1];
                    vc[i] = cnt[c][i+1];
                }

                vector<int> cur(3,0);
                cur[0] = va[0]; cur[1] = vb[1]; cur[2] = vc[2];

                int cost = 0;

                // a-b swap, b-c swap, c-a swap
                int t = min(va[1], vb[0]);
                if (t > 0) {
                    cost += t;
                    cur[0] += t; cur[1] += t;
                    va[1] -= t; vb[0] -= t;
                }
                t = min(vb[2], vc[1]);
                if (t > 0) {
                    cost += t;
                    cur[1] += t; cur[2] += t;
                    vb[2] -= t; vc[1] -= t;
                }
                t = min(va[2], vc[0]);
                if (t > 0) {
                    cost += t;
                    cur[0] += t; cur[2] += t;
                    va[2] -= t; vc[0] -= t;
                }

				// a's from c->b->a swap
                t = min({va[2], vc[1], vb[0]});
                if (t > 0) {
                    cost += 2*t;
                    cur[0] += t; cur[1] += t; cur[2] += t;
                    va[2] -= t; vb[0] -= t; vc[1] -= t;
                }

                // a's from b->c->a
                t = min({va[1], vc[0], vb[2]});
                if (t > 0) {
                    cost += 2*t;
                    cur[0] += t; cur[1] += t; cur[2] += t;
                    va[1] -= t; vc[0] -= t; vb[1] -= t;
                }        
				
                cost += n - cur[0] - cur[1] - cur[2];
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << '\n';
} 


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;++i) {
        solve();
    }
    return 0;
}