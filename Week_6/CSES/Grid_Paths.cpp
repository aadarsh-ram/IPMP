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
        int n; cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            for (int j=0; j<n; j++) {
                arr[i][j] = s[j];
            }
        }
        vector<vi> dp(n, vi(n, 0));
        dp[0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (arr[i][j] == '.') {
                    if (i > 0) {
                        // Can come from left
                        dp[i][j] += dp[i-1][j];
                        dp[i][j] %= 1000000007;
                    }
                    if (j > 0) {
                        // Can come from top
                        dp[i][j] += dp[i][j-1];
                        dp[i][j] %= 1000000007;
                    }
                } else dp[i][j] = 0; // No path from trap
            }
        }
        cout << dp[n-1][n-1] << endl;
    }
}