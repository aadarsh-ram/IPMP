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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int m; cin >> m;
        vi arr(n);
        int ans = n*(n+1)/2; // Sum of all natural nos
        for (int i=0; i<m; i++) {
            cin >> arr[i];
            // Keep removing from sum, until missing element remains
            ans -= arr[i]; 
        }
        cout << ans;
    }
}