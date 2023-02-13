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
        int n, k; cin >> n >> k;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        unordered_map<int, pair<int, int>> mp;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                mp[arr[i] + arr[j]] = {i,j};
            }
        }
        int flag = 0;
        for (int i=0; i<n-1; i++) {
            for (int j=i+1; j<n; j++) {
                int sum = arr[i] + arr[j];
                auto it = mp.find(k-sum);
                if (it != mp.end()) {
                    int ind1 = it->second.first;
                    int ind2 = it->second.second;
                    if (ind1 != i && ind1 != j && ind2 != i && ind2 != j) {
                        cout << arr[ind1] << " " << arr[ind2] << " " << arr[i] << " " << arr[j];
                        flag = 1; break;
                    }
                }
            }
            if (flag == 1) break;
        }
    }
}