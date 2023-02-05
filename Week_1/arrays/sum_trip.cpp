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
    int t; cin >> t;
    while (t--) {
        int n, sum; cin >> n >> sum;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int l, r;
        for (int i=0; i<n-2; i++) {
            l = i + 1;
            r = n-1;
            while (l < r) {
                if (arr[i] + arr[l] + arr[r] == sum) {
                    cout << arr[i] << " " << arr[l] << " " << arr[r] << endl;
                    break;
                } else if (arr[i] + arr[l] + arr[r] < sum) {
                    l++;
                } else {
                    r++;
                }
            }
        }
    }
}