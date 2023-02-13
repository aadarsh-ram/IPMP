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
        int flag = 0;
        for (int i=0; i<n; i++) {
            if (arr[i] == 1) {
                flag = 1; break;
            }
        }
        if (flag == 1) cout << 1 << endl;
        else {
            for (int i=0; i<n; i++) {
                if (arr[i] <= 0 || arr[i] > n) {
                    arr[i] = 1;
                }
            }
            for (int i=0; i<n; i++) {
                arr[(arr[i]-1) % n] += n;
            }
            int done = 0;
            for (int i=0; i<n; i++) {
                if (arr[i] <= n) {
                    cout << i+1 << endl;
                    done = 1; break;
                }
            }
            if (done == 0) {
                cout << n+1 << endl;
            }
        }
    }
}