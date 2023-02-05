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
        vi arr(n);
        multiset<int> ss;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            auto it = ss.find(arr[i]);
            if (it != ss.end()) {
                ss.erase(arr[i]); // Erase from set if occurence there
            } else {
                ss.insert(arr[i]);
            }
        }
        for (auto it: ss) {
            cout << it << " ";
        }
    }
}