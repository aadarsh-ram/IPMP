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
// https://www.youtube.com/watch?v=MxhA0bY31wM

vector<vi> dp(1000005, vi(8, 0)); // 8 possible building blocks of 2x2
int maxN = 1;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i=0; i<8; i++) {
        dp[0][i] = 1; // First block can be any one from the 8
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (maxN >= n) {
            // Don't need to recompute value everytime
            // Previous n values will also be stored
            cout << (dp[n-1][2]+dp[n-1][6])%MOD << endl;
        } else {
            for (int i=maxN; i<n; i++) {
                for (int j=0; j<8; j++) {
                    // Each state can transition to some fixed states 
                    // as per the previous block pattern.

                    // Check the numbering convention in the video
                    if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                        // The previous block should have a vertical line at the top
                        dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3]
                            + dp[i-1][4] + dp[i-1][5]) % MOD;
                    } else {
                        // The previous block should have no vertical line at the top
                        dp[i][j] = (dp[i-1][2] + dp[i-1][6] + dp[i-1][7])%MOD;
                    }
                }
            }
            // The final number of towers will be the sum of ways
            // where the tower ends with blocks with index 2 and 6
            cout << (dp[n-1][2]+dp[n-1][6])%MOD << endl;
            maxN = n;
        }
    }
}