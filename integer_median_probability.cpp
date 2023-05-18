
/*

You are picking N integers, all in the range [1, M] uniformly at random, independent of each other.

Find the probability that the median of these N numbers is an integer.

The median of a collection S of size K is defined to be the (K + 1) / 2-th smallest element of S if K is odd and the average of K/2-th and K/2 + 1-th smallest elements of S if K is even.

Input Format
The only line of the input contains two space separated integers, N and M.

Constraints
1 ≤ N, M ≤ 5 * 10^5

Output Format
If the answer can be expressed as a fraction P/Q in its lowest form, print P * Q^-1 modulo 998244353, where Q^-1 denotes the modular inverse of Q wrt 998244353.

Sample
Input
2 3
Output
221832079
Explanation
There are 9 possibilities for the chosen values.
Out of them, the following have an integer median: [1, 1], [2, 2], [3, 3], [1, 3], [3, 1].
Hence the probability is 5/9.
So answer = 5 * 9^-1 modulo 998244353 = 221832079.


*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int powerr(int b, int e) {
    int res = 1;
    while(e > 0) {
        if (e%2) {
            res = (res * b) % mod;
        }
        e/=2;
        b = (b*b)%mod;
    }
    return res;
}



void solve() {

    int n, m;

    cin >> n >> m;

    if ((n%2) == 1) {
        cout << "1\n"; return ;
    }

    vector<int> fact(n+1, 1), ifact(n+1, 1);

    function<int(int)> mod_inv = [] (int i) {
        return powerr(i, mod - 2);
    };

    for(int i=2;i<=n;++i) {
        fact[i] = (fact[i-1] * i) % mod;
        ifact[i] = (ifact[i-1] * mod_inv(i)) % mod;
    }

    function<int(int, int)> nCr = [&] (int n, int r) {
        return fact[n] * ifact[n-r] % mod * ifact[r] % mod; 
    };

    vector<int> dp(m+2, 0);

    for(int i=m; i>=1;--i) {
        dp[i] = (mod + powerr(m-i+1, n/2) - powerr(m-i, n/2)) % mod;
        if (i + 2 <= m) {
            dp[i] += dp[i+2];
            dp[i] %= mod;
        }
    }

    int ans = 0;

    for(int l=1;l<=m;++l) {
        int t = (mod + powerr(l, n/2) - powerr(l-1, n/2)) % mod;
        t = (t * dp[l+1]);
        ans += t;
        ans %= mod;
    }

    ans *= nCr(n,n/2);
    ans %= mod;
    ans = (mod + powerr(m, n) - ans)%mod;
    ans = (ans * mod_inv(powerr(m,n))) % mod;
    cout << ans << '\n';
} 


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;++i) {
        solve();
    }
    return 0;
}