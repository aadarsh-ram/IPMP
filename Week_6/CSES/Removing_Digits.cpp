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
        vi dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=0; i<=n; i++) {
            int temp = i;
            while (temp != 0) {
                int x = temp%10;
                // DP transition
                dp[i] = min(dp[i], dp[i-x]+1);
                temp /= 10;
            }
        }
        cout << dp[n] << endl;
    }
}