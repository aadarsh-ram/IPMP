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
        string t; getline(cin, t);
        int ans = INT_MAX;
        int start = 0, cnt = 0;
        vi mp(256, 0);
        for (int i=0; i<t.length(); i++) {
            if (mp[t[i]] == 0) {cnt++;}
            mp[t[i]]++;
        }
        int i=0, j=0;
        while (j<s.length()) {
            // Reduce window size till count = 0
            mp[s[j]]--;
            if (mp[s[j]] == 0) {cnt--;}
            if (cnt == 0) {
                while (cnt == 0) {
                    // Find min length
                    if (ans > j-i+1) {
                        ans = min(ans, j-i+1);
                        start = i;
                    }
                    // Increase window size again
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {cnt++;}
                    i++;
                }
            }
            j++;
        }
        if (ans != INT_MAX) {
            cout << s.substr(start, ans) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}