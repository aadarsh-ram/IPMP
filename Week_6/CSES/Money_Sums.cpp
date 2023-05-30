#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;
// Check codeforces editorial for better explanation
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int max_sum = n*1000;
        // Stores whether we can reach a target, with some set of coins
        vector<vi> dp(n+1, vi(max_sum+1, 0));
        dp[0][0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=max_sum; j++) {
                dp[i][j] = dp[i-1][j]; // Don't choose a coin
                int left = j-arr[i-1];
                // Choose a coin, and check if we can make "left"
                // using current set of coins
                if (left >= 0 && dp[i-1][left]) {
                    dp[i][j] = 1;
                }
            }
        }
        vi possible;
        for (int i=1; i<=max_sum; i++) {
            if (dp[n][i]) {
                possible.push_back(i);
            }
        }
        cout << possible.size() << endl;
        for (auto i: possible) {
            cout << i << " ";
        }
        cout << endl;
    }
}