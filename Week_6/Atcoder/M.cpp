#include <iostream>
#include <vector>
#define ll long long
const int MOD = 1e9+7;

using namespace std;
// https://www.youtube.com/watch?v=dviTaAZRqCo
int main() {
    ll n, k;
    cin >> n; cin >> k;
    vector<ll> arr(n+1);
    for(int i=1; i<=n; i++) {
        int x; cin >> arr[i];
    }
    // Create table with 0..k candies and 0..n people.
    int dp[n+1][k+1];
    dp[0][0] = 1;
    // There's only one way (i.e. with 0 people) to distribute 0 candies
    for (int i=1; i<=k; i++) {
        dp[0][i] = 0;
    }
    // There's always one way to distribute 0 candies to all people
    for (int i=1; i<=n; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<=n; i++) {
        vector<int> sum(k+1);
        sum[0] = dp[i-1][0];
        // Prefix sum of before array
        for (int j=1; j<=k; j++) {
            sum[j] = (sum[j-1]+dp[i-1][j])%MOD;
        }
        // If current candies exceed what person can hold,
        // need to subtract prefix sum of curr_candies - (what person can hold) - 1
        for (int j=0; j<=k; j++) {
            if (j<=arr[i]) {
                dp[i][j] = sum[j];
            }
            else {
                int pref_to_rem = j-arr[i]-1;
                dp[i][j] = (sum[j]-sum[pref_to_rem]+MOD)%MOD;
            }
        }
        sum.clear();
    }
    // for (int i=0; i<=n; i++) {
    //     for (int j=0; j<=k; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n][k] << '\n';
    return 0;
}