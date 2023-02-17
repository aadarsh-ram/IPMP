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
        string s1; string s2;
        cin >> s1; cin >> s2;
        vi arr(26, 0);
        int curr = 0;
        for (int i=0; i<s2.size(); i++) {
            arr[s2[i] - 'a'] = -1;
        }
        for (int i=0; i<s1.size(); i++) {
            if (arr[s1[i] - 'a'] != -1) {
                s1[curr] = s1[i]; curr++;
            }
        }
        for (int i=0; i<curr; i++) {
            cout << s1[i];
        }
    }
}