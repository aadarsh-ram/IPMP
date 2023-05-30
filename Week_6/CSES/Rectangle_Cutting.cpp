#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int a, b; cin >> a >> b;
        vector<vi> dp(a+1, vi(b+1, 1e9));
        for (int i=0; i<=a; i++) {
            for (int j=0; j<=b; j++) {
                if (i == j) dp[i][j] = 0; // Zero operations for h == w
                else {
                    for (int k=1; k<i; k++) {
                        // Cut it horizontally at kth position
                        dp[i][j] = min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
                    }
                    for (int k=1; k<j; k++) {
                        // Cut it vertically at kth position
                        dp[i][j] = min(dp[i][j], dp[i][j-k]+dp[i][k]+1);
                    }
                }
            }
        }
        cout << dp[a][b] << endl;
    }
}