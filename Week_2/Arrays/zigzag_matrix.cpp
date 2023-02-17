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
        vector<vi> mat(r, vi(c));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> mat[i][j];
            }
        }
        for (int line=1; line<r+c; line++) {
            // Traverse first col, then line-row for others
            int startcolumn = max((int)0, line-r);
            // Count of elements in a line
            int count = min(min(line, c-startcolumn), r);
            for (int j=0; j<count; j++) {
                cout << mat[min(r, line)-j-1][startcolumn+j] << " ";
            }
            cout << endl;
        }

    }
}