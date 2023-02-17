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
        int maxx=0, minn=0;
        int i;
        if (n%2 == 0) {
            maxx = max(arr[0], arr[1]);
            minn = min(arr[0], arr[1]);
            i = 2;
        }
        else {
            maxx = arr[0]; minn = arr[0];
            i = 1;
        }
        while (i < n) {
            int maxe = max(arr[i], arr[i+1]);
            int mine = min(arr[i], arr[i+1]);
            if (maxe > maxx) maxx = maxe;
            if (mine < minn) minn = mine;
            i += 2;
        }
        cout << maxx << " " << minn << endl;
    }
}