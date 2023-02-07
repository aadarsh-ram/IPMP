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
        int n; cin >> n;
        int m; cin >> m;
        vi arr1(n); vi arr2(m);
        for (int i=0; i<n; i++) {
            cin >> arr1[i];
        }
        for (int i=0; i<m; i++) {
            cin >> arr2[i];
        }
        vi union_arr, inter_arr;
        int i=0, j=0;
        while (i < n && j < m) {
            if (arr1[i] == arr2[j]) {
                inter_arr.pb(arr1[i]);
                union_arr.pb(arr1[i]);
                i++; j++;
            }
            else if (arr1[i] < arr2[j]) {
                union_arr.pb(arr1[i]);
                i++;
            }
            else {
                union_arr.pb(arr2[j]);
                j++;
            }
        }
        while (i < n) {
            union_arr.pb(arr1[i]);
            i++;
        }
        while (j < m) {
            union_arr.pb(arr2[j]);
            j++;
        }
        for (int i=0; i<union_arr.size(); i++) cout << union_arr[i] << " ";
        cout << endl;
        for (int i=0; i<inter_arr.size(); i++) cout << inter_arr[i] << " ";
    }
}