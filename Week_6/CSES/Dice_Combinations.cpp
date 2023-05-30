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

vi dp(1000005, -1);

int ways(int curr, int target) {
    if (curr > target) return 0;
    if (curr == target) return 1;
    if (dp[curr] != -1) return dp[curr];

    int curr_ways = 0;
    for (int i=1; i<7; i++) {
        curr_ways += (ways(curr+i, target) % MOD);
    }
    return dp[curr] = curr_ways;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        cout << ways(0, n)%MOD << endl;
    }
}