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
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            mp[arr[i]] += 1;
        }
        bool flag = 0;
        for (int i=0; i<n; i++) {
            auto it = mp.find(sum-arr[i]);
            if (it != mp.end()) {
                if (sum-arr[i] == arr[i] && it->second <= 1) continue;
                cout << arr[i] << " " << sum-arr[i] << endl;
                flag = 1; break;
            }
        }
        if (flag == 0) cout << "No pair found" << endl;
    }
}