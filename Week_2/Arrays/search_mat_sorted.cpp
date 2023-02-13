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
        int n, m, k; cin >> n >> m >> k;
        vector<vi> arr(n, vi(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        if (k < arr[0][0] || k > arr[n-1][m-1]) {
            cout << -1 << endl;
        } else {
            int p = 0, q = n-1;
            int flag = 0;
            while (p < n && q >= 0) {
                if (arr[p][q] == k) {
                    cout << "Found" << endl;
                    flag = 1; break;
                }
                if (arr[p][q] > k) q--;
                else p++;
            }
            if (flag == 0) cout << "Not found" << endl;
        }
    }
}