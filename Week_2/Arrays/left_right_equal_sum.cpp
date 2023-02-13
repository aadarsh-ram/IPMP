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
        int left_sum = 0, right_sum = 0;
        int p=0, q=n-1;
        for (int i=0; i<n; i++) {
            if (p == q && left_sum == right_sum) {
                cout << arr[p] << endl;
                break;
            }
            if (p == q) {
                cout << -1 << endl;
            }
            else if (left_sum >= right_sum) {
                right_sum += arr[q];
                q--;
            } else {
                left_sum += arr[p];
                p++;
            }
        }
    }
}