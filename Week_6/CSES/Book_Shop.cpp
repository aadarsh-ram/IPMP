#include <bits/stdc++.h>
#define endl '\n'
#define vi vector<int>
#define pb push_back
 
using namespace std;
 
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n, x; cin >> n >> x;
        vi prices(n);
        vi pages(n);
        for (int i=0; i<n; i++) {
            cin >> prices[i];
        }
        for (int i=0; i<n; i++) {
            cin >> pages[i];
        }
        vector<vi> dp(n+1, vi(x+1, 0));
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=x; j++) {
                dp[i][j] = dp[i-1][j]; // Not taking the book
                if (j-prices[i-1] >= 0) {
                    // Taking the book
                    dp[i][j] = max(dp[i][j], dp[i-1][j-prices[i-1]]+pages[i-1]);
                }
            }
        }
        cout << dp[n][x] << endl;
    }
}