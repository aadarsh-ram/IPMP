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
        sort(arr.begin(), arr.end());
        int min_diff = 100000000;
        for (int i=1; i<n; i++) {
            if (min_diff > arr[i]-arr[i-1]) {
                min_diff = arr[i]-arr[i-1];
            }
        }
        cout << min_diff << endl;
    }
}