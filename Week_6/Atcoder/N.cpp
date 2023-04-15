#include <iostream>
#include <cstring>
#include <vector> 
#define int long long

using namespace std;
int pref[401];
vector<int> arr;
int dp[401][401];

int sumrange(int l, int r) {
    if (l==0) return pref[r];
    return pref[r] - pref[l-1];
}

int ans(int l, int r) {
    if (l==r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int res = 1000000000000000000;
    for (int i=l; i<r; i++) {
        int curr = ans(l, i) + ans(i+1, r) + sumrange(l,i) + sumrange(i+1, r);
        res = min(curr, res);
    }
    return dp[l][r] = res;
}
 
signed main() {
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    pref[0] = arr[0];
    for (int i=1; i<n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << ans(0,n-1) << '\n';
    return 0;
}