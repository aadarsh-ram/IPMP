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
        vector<vi> arr;
        for (int i=0; i<n; i++) {
            int s, e, r; cin >> s >> e >> r;
            arr.push_back({e, s, r});
        }
        sort(arr.begin(), arr.end()); // Sort by end time
        int bestTotalReward = 0;
        map<int, int> dp; // Stores at time "end" mapped to "best reward" at that time
        dp[0] = 0;
        for (auto project: arr) {
            int end = project[0], start = project[1], reward = project[2];
            // Find the "end" with doesn't overlap with current start
            auto it = dp.lower_bound(start); it--;
            int totalReward = it->second + reward; // Add prev reward with current
            bestTotalReward = max(bestTotalReward, totalReward);
            dp[end] = bestTotalReward;
        }
        cout << bestTotalReward << endl;
    }
}