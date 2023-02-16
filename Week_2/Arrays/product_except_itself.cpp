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
        vi pref(n), suff(n);
        int temp=1;
        for (int i=0; i<n; i++) {
            temp *= arr[i];
            pref[i] = temp;
        }
        temp=1;
        for (int i=n-1; i>=0; i--) {
            temp *= arr[i];
            suff[i] = temp;
        }
        vi prod(n);
        for (int i=0; i<n; i++) {
            if (i == 0) prod[i] = suff[i+1];
            else if (i == n-1) prod[i] = pref[i-1];
            else {
                prod[i] = suff[i+1]*pref[i-1];
            }
        }
        if (n == 1) prod[0] = 1;
        for (auto i: prod) {
            cout << i << " ";
        }
    }
}