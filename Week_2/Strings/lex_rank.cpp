#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int fact(int n) {
    if (n < 1) return 1;
    else return n*fact(n-1);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int rank = 1, mul = fact(n);
        int cnt[256] = {0};
        // Count frequency
        for (int i=0; i<n; i++) {
            cnt[s[i]] += 1;
        }
        // Prefix count
        for (int i=1; i<256; i++) {
            cnt[i] += cnt[i-1];
        }
        for (int i=0; i<n; i++) {
            mul /= (n-i);
            rank += cnt[s[i]-1] * mul;
            for (int j=s[i]; j<256; j++) {
                cnt[j]--;
            }
        }
        cout << rank << endl;
    }
}