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
        map<int, int> mp;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            if (mp.find(arr[i]) == mp.end()){
                mp[arr[i]]=1;
            }
            else{
                mp[arr[i]]+=1;
            }
        }
        vector<pair<int, int>> freqarr;
        for (auto i: mp) freqarr.push_back({i.second, i.first});
        sort(freqarr.begin(), freqarr.end());
        reverse(freqarr.begin(), freqarr.end());
        for (auto i: freqarr) {
            for (int j=0; j<i.first; j++) cout << i.second <<" ";
        }
    }
}