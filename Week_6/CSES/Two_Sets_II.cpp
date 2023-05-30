#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back
#define MOD 1000000007

using namespace std;

// Check codeforces editorial for bettee explanation
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        int s = n*(n+1)/2;
        if (s%2 == 1) {
            cout << 0 << endl;
            return 0;
        }
        int target = s/2; // Need to get half of sum
        vector<vi> dp(n+1, vi(s+1, 0));
        dp[0][0] = 1;

        // Loop is till n-1, since we always assume that we put "n" in second set
        for (int i=1; i<n; i++) {
            for (int j=0; j<=target; j++) {
                // Don't include current element
                dp[i][j] = dp[i-1][j];
                int left = j - i;
                if (left >= 0) {
                    // Include current element
                    (dp[i][j] += dp[i-1][left]) %= MOD;
                }
            }
        }
        cout << dp[n-1][target]%MOD << endl;
    }
}