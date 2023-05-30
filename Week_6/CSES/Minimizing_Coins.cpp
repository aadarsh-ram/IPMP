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
        int n, x; cin >> n >> x;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vi dp(x+5, 1e9);
        dp[0] = 0; // Base case
        for (int i=1; i<=x; i++) {
            // Looping for each target
            for (int j=0; j<n; j++) {
                if (i-arr[j] >= 0) {
                    // Take coin or not take coin
                    dp[i] = min(dp[i], dp[i-arr[j]]+1);
                }
            }
        }
        if (dp[x] != 1e9) cout << dp[x] << endl;
        else cout << -1 << endl;
    }
}