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
        vi dp(x+5, 0);
        dp[0] = 1; // Base case
        for (int j=0; j<n; j++) {
            for (int i=0; i<=x; i++) {
                // Looping for each coin, for different targets
                // This way, it ensures same set of coins aren't ordered differently
                if (i-arr[j] >= 0) {
                    // Take coin or not take coin
                    dp[i] += dp[i-arr[j]];
                    dp[i] %= 1000000007;
                }
            }
        }
        cout << dp[x] << endl;
    }
}