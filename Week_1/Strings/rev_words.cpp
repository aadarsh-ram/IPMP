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
        string s; getline(cin, s);
        vector<string> v;
        string curr = "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                v.pb(curr);
                curr = "";
            } else {
                curr += s[i];
            }
        }
        v.pb(curr);
        reverse(v.begin(), v.end());
        for (int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        } 
    }
}