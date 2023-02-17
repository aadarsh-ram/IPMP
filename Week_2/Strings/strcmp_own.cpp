#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int strcmp_own(string s1, string s2) {
    int i;
    for (i=0; s1[i]&&s2[i]; i++) {
        if (s1[i] == s2[i]) continue;
        else {
            if (s1[i] > 90 && s2[i] < 90) {
                int x = s1[i] - 32;
                if (x == s2[i]) continue;
                else break;
            }
            else if (s1[i] < 90 && s2[i] > 90) {
                int x = s2[i] - 32;
                if (x == s1[i]) continue;
                else break;
            }
            else {
                break;
            }
        }
    }
    if (s1[i] == s2[i]) return 0;
    if (s1[i] > 90 && s2[i] < 90) {
        int x = s1[i] - 32;
        if (x != s2[i]) return -1;
    }
    else if (s1[i] < 90 && s2[i] > 90) {
        int x = s2[i] - 32;
        if (x != s1[i]) return -1;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string s1, s2; cin >> s1; cin >> s2;
        cout << strcmp_own(s1, s2) << endl;
    }
}