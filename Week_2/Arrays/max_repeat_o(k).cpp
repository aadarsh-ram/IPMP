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
        for (int i=0; i<n; i++) {
            arr[arr[i]%k] += k;
        }
        int mx = arr[0], res = 0;
        for (int i=1; i<n; i++){
            if (arr[i] > mx) {
                mx = arr[i]; res = i;
            }
        }
        for (int i=0; i<n; i++) arr[i] %= k; // Bring back original array
        cout << arr[res] << endl;
    }
}