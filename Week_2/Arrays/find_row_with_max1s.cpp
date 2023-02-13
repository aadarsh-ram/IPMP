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
        int i=0, j=0;
        int ans = -1;
        while (i < n && j >= 0) {
            if (arr[i][j] == 1) {
                if (j == 0) {
                    ans = m; break;
                }
                else {
                    ans = max(m-j, ans);
                    if (arr[i][j-1] == 0) {
                        i++; j--;
                    } else {
                        j--;
                    }
                }
            } else {
                if (ans != -1) {
                    i++;
                }
                else {
                    if (j < m) { j++; }
                    else {
                        i++; j = 0;
                    }
                }
            }
        }
        if (ans == -1) {
            cout << m-j << endl;
        } else {
            cout << ans << endl;
        }
    }
}