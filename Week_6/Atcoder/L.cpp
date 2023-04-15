#include <iostream>
#include <vector>
#include <cstring>
#define ll long long

using namespace std;

vector<ll> arr;
ll dp[3001][3001][2];

// Aim: To maximize x-y for Taro and minimize x-y for Jiro by playing optimally.
// In Taro's turn, the sum for Taro is tried to be maximized, by choosing appropriate way.
// In Jiro's turn, the sum for Taro is tried to be minimized, by choosing appropriate way.

ll ans(ll l, ll r, ll move) {
    // If all elements are taken
    if (l > r) {
        return 0;
    }
    ll p = arr[l]; ll q = arr[r];
    ll val1, val2;
    // Check for current person and array, if problem is solved
    if (dp[l][r][move] != -1) {
        return dp[l][r][move];
    }
    // Check if move is for Taro
    if (move == 1) {
        val1 = p+ans(l+1, r, 0); // Take first element and add to values picked by Taro already
        val2 = q+ans(l, r-1, 0); // Take last element and add to values picked by Taro already
        return dp[l][r][move] = max(val1, val2); // Check which way gives a max value
    }
    // Move is for Jiro
    else {
        val1 = ans(l+1, r, 1); // Leave first element to be taken by Jiro afterwards
        val2 = ans(l, r-1, 1); // Leave last element to be taken by Jiro afterwards
        return dp[l][r][move] = min(val1, val2); // Check which way gives a min value
    }
}

int main() {
    ll n; cin >> n;
    ll total = 0;
    // Input
    for (int i=0; i<n; i++) {
        ll x; cin >> x;
        total += x;
        arr.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    ll s_taro = ans(0, n-1, 1);
    // Since, the function gives maximized sum of Taro, Jiro can choose the remaining elements.
    // The sum of remaining elements = Total - (sum of Taro)
    ll s_jiro = total-s_taro;
    cout << s_taro-s_jiro << '\n';
    return 0;
}