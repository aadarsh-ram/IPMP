#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

bool cmp(int x, int y) {
    return abs(x) < abs(y);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        int min_diff = 10000000000;
        int x, y;
        for (int i=1; i<n; i++) {
            if (abs(arr[i]+arr[i-1]) <= min_diff) {
                min_diff = abs(arr[i]+arr[i-1]);
                x = arr[i]; y = arr[i-1];
            }
        }
        cout << x << " " << y << endl;
    }
}