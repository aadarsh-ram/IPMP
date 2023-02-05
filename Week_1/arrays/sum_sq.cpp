#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

// https://leetcode.com/problems/sum-of-square-numbers/

using namespace std;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int a=0; a*a <= n; a++) {
            int sr = sqrt(n-(a*a));
            if (sr*sr == n-(a*a)) {
                cout << a << " " << sr << endl;
                break;
            }
        }
    }
}