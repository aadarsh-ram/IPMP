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
        string s; cin >> s;
        int n = s.size();
        vi arr(256, -1);
        for (int i=0; i<n; i++) {
            if (arr[i] == -1) arr[s[i]] = i;
            else {
                arr[s[i]] = -2;
            }
        }
        int res = INT_MAX;
        for (int i=0; i<256; i++) {
            if (arr[i] >= 0) {
                res = min(res, arr[i]);
            }
        }
        if (res == INT_MAX) cout << -1 << endl;
        else cout << s[res] << endl;
    }
}