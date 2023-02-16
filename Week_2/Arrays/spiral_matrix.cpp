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
        int m, n; cin >> m >> n;
        int arr[m][n];
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cin >> arr[i][j];
            }
        }
        int top=0, bottom=m-1, left=0, right=n-1;
        while ((left <= right) && (top <= bottom)) {
            for (int i=left; i<=right; i++) {
                cout << arr[top][i] << " ";
            }
            top++;
            for (int i=top; i<=bottom; i++) {
                cout << arr[i][right] << " ";
            }
            right--;
            if ((left > right) || (top > bottom)) break;
            for (int i=right; i>=left; i--) {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
            for (int i=bottom; i>=top; i--) {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}