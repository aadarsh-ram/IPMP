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
        int n, k; cin >> n >> k;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        map<int, int> mp;
        int s=0;
        for (int i=0; i<n; i++) {
            s += arr[i];
            if (s == k) {
                cout << 0 << " " << i << endl;
                break;
            }
            if (mp.find(s-arr[i]) != mp.end()) {
                cout << mp[s-arr[i]] + 1 << " " << i << endl;
            }
        }
    }
}