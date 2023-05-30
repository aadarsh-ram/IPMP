#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int dp[5005][5005][2];

int ans(int i, int j, vi &arr, int turn) {
    if (i > j) return 0;
    if (dp[i][j][turn] != -1) return dp[i][j][turn];
    if (turn == 0) {
        // Need to maximize score of 1st player
        return dp[i][j][turn] = max(arr[i]+ans(i+1,j,arr,1), arr[j]+ans(i,j-1,arr,1));
    } else {
        // Need to maximize score of 2nd player
        // by not allowing 1st player to take element which gives more sum
        return dp[i][j][turn] = min(ans(i+1,j,arr,0),ans(i,j-1,arr,0));
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << ans(0, n-1, arr, 0) << endl;
    }
}