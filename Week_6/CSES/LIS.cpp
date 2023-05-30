#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;
// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#solution-in-on-log-n-with-dynamic-programming-and-binary-search
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vi dp(n+1, INT_MAX); // Stores the element at which LIS ends in (length = index)
        dp[0] = INT_MIN; // Index 0 = -INF
        for (int i=0; i<n; i++) {
            // Finds which element to replace
            int l = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            // Checks if current element, can be replaced with a smaller element
            if (dp[l-1] < arr[i] && arr[i] < dp[l]) dp[l] = arr[i];
        }
        int ans = 0;
        for (int i=0; i<=n; i++) {
            // The maximum index, which doesn't have inf is the answer
            if (dp[i] < INT_MAX) ans = i;
        }
        cout << ans << endl;
    }
}