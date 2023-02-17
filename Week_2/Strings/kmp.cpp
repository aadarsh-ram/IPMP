#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void lps(string &pat, int m, vi &lpsArr) {
    int len = 0;
    lpsArr[0] = 0;
    for (int i=1; i<m; i++) {
        if (pat[i] == pat[len]) {
            len++; lpsArr[i] = len;
        } 
        else {
            if (len != 0) len = lpsArr[len - 1];
            else {
                lpsArr[i] = 0;
            }
        }
    }
}

void KMPAlgorithm(string &text, string &pattern, int n, int m) {
    vi lpsArr(m); lps(pattern, m, lpsArr);
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++; i++;
        }
        if (j == m) {
            cout << "Found pattern at index " << (i - j) << endl;
            j = lpsArr[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lpsArr[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string s,p; cin >> s; cin >> p;
        KMPAlgorithm(s, p, s.size(), p.size());
    }
}