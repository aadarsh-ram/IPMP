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
        string a, b; cin >> a; cin >> b;
        map <char, int> mp;
        for (int i=0; i<a.size(); i++) {
            mp[a[i]]++;
        }
        for (int i=0; i<b.size(); i++) {
            if (mp.find(b[i]) != mp.end()) {
                mp[b[i]]--;
            }
        }
        int flag = 0;
        for (auto i: mp) {
            if (i.second != 0) {
                cout << "NO" << endl;
                flag=1; break;
            } 
        }
        if (flag == 0) cout << "YES" << endl;
    }
}