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
        string s; cin >> s;
        if (s.length() == 0) cout << 0 << endl;
        if (s.length() == 1) cout << 1 << endl;
        int maxLength = 0;
        vi vis(256, 0);
        int l=0, r=0;
        for (r=0; r < s.length(); r++) {
            if (vis[s[r]] == 0) vis[s[r]] = 1;
            else {
                maxLength = max(maxLength, r-l); // Length of unique string
                while (l != r) {
                    // Mark all chars visited until repeating char
                    if (s[l] != s[r]) {vis[s[l]] = 0;}
                    else { l++; break;}
                    l++;
                }
            }
        }
        maxLength = max(maxLength, r-l);
        cout << maxLength << endl;
    }
}