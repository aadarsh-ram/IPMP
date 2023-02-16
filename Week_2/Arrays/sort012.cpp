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
        int cnt0=0, cnt1=0, cnt2=0;
        for (auto i: arr) {
            if (i == 0) cnt0++;
            if (i == 1) cnt1++;
            if (i == 2) cnt2++;
        }
        int j=0;
        while (cnt0--) arr[j++] = 0; 
        while (cnt1--) arr[j++] = 1;
        while (cnt2--) arr[j++] = 2;
        for (auto i: arr) cout << i << " ";
    }
}