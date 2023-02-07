#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;
void permute(string &s, int l, int r) {
    if (l == r) cout << s << endl;
    else {
        for (int i=l; i<=r; i++) {
            char temp = s[l]; s[l] = s[i]; s[i] = temp; // Swap
            permute(s, l+1, r);
            temp = s[l]; s[l] = s[i]; s[i] = temp; // Swap
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string s; cin >> s;
        permute(s, 0, s.size()-1);
    }
}