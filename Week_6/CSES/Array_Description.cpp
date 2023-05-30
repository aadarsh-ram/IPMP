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

// https://www.youtube.com/watch?v=dNQ8x342FCQ
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n, m; cin >> n >> m;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        // prev stores number of ways to fill the array for a previous array element
        // dp stores number of ways to fill the array for current element, using prev
        vi prev(m+1), dp(m+1);

        if (arr[0] == 0) {
            // Any value can come at the first position
            // Starting from index 1 to m
            fill(prev.begin()+1, prev.end(), 1);
        } else {
            // Only that value can come
            prev[arr[0]] = 1;
        }
        for (int i=1; i<n; i++) {
            // Lower and upper bound for the values which can be filled
            int lowerBound = arr[i] == 0 ? 1 : arr[i];
            int upperBound = arr[i] == 0 ? m : arr[i];
            for (int j=lowerBound; j<=upperBound; j++) {
                (dp[j] += prev[j]) %= MOD; // Prev element can be filled again always
                if (j > 1) (dp[j] += prev[j-1]) %= MOD; // (Prev element - 1) can be filled
                if (j < m) (dp[j] += prev[j+1]) %= MOD; // (Prev element + 1) can be filled
            }
            // Switch prev and dp, and reinitialize dp
            swap(dp, prev);
            fill(dp.begin(), dp.end(), 0);
        }
        // Total number of ways is the sum of ways of the last array element
        int ans = 0;
        for (auto i: prev) {
            (ans += i) %= MOD;
        }
        cout << ans%MOD << endl;
    }
}