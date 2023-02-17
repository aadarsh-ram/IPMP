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
        int n, m; cin >> n >> m;
        int arr[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        int ans[m][n];
        for (int r=0; r<n; r++) {
            for (int c=0; c<m; c++) {
                ans[c][n-r-1] = arr[r][c];
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}