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
        int r, c; cin >> r >> c;
        int arr[r][c];
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> arr[i][j];
            }
        }
        int row_flag = 0;
        int col_flag = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                // Set flags for row and col
                if (i == 0 && arr[i][j] == 1) {row_flag = 1;}
                if (j == 0 && arr[i][j] == 1) {col_flag = 1;}
                // Set 1's at top of current col and left of current row
                if (arr[i][j] == 1) {
                    arr[0][j] = 1;
                    arr[i][0] = 1;
                }
            }
        }
        for (int i=1; i<r; i++) {
            for (int j=1; j<c; j++) {
                // If starting is 1, then entire row/col is 1
                if (arr[0][j] == 1 || arr[i][0] == 1) {
                    arr[i][j] = 1;
                }
            }
        }
        if (row_flag == 1) {
            for (int i=0; i<c; i++) {
                arr[0][i] = 1;
            }
        }
        if (col_flag == 1) {
            for (int i=0; i<r; i++) {
                arr[i][0] = 1;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
}