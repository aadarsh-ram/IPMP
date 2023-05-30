#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;
// Check codeforces CSES editorial for better explanation
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string a, b;
        cin >> a; cin >> b;
        int n=a.size(), m=b.size();
        vector<vi> dp(n+1, vi(m+1, 1e9));
        dp[0][0] = 0;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (i) {
                    // Delete a character from "a" at current index
                    // Compare a[:i-1] and b[:j]
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
                if (j) {
                    // Add a character to "a" at current index
                    // Compare a[:i] and b[:j-1]
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
                if (i && j) {
                    // Replace current character at current index
                    // Compare a[:i-1] and b[:j-1]
                    // Operation required only when unequal
                    int is_unequal = a[i-1] != b[j-1];
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+is_unequal);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}