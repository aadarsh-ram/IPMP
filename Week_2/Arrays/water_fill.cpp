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
        int k, r, c; cin >> k >> r >> c;
        float arr[100][100];
        arr[0][0] = k;
        for (int i=1; i<100; i++) {
            for (int j=0; j<i; j++) {
                float rem_water = (arr[i-1][j] - 1)/2;
                if (rem_water > 0) {
                    arr[i][j] += rem_water;
                    arr[i][j+1] += rem_water;
                }   
            }
        }
        if (arr[r-1][c-1] > 1) cout << 1 << endl;
        else {
            cout << arr[r-1][c-1] << endl;
        }
    }
}