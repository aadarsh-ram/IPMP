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
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int min_ind = 0;
        int ans = 0;
        for (int i=1; i<n; i++) {
            if (arr[min_ind] > arr[i]) min_ind = i;
            else {
                ans = max(ans, arr[i]-arr[min_ind]);
            }
        }
        cout << ans << endl;
    }
}