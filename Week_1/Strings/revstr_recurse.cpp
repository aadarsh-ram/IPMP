#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void reverseStr(string &s, string &rev, int index, int n) {
    if (index == n) return;
    reverseStr(s, rev, index+1, n);
    rev += s[index];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string inp; cin >> inp;
    string revString = "";
    reverseStr(inp, revString, 0, inp.size());
    cout << revString;
}