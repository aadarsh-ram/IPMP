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
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        string temp = "";
        int len = 0;
        int j=0;
        while (j < n) {
            if (temp == "") {temp += s[j]; len++; j++;}
            else {
                if (temp[0] == s[j]) {len++; j++;}
                else {
                    ans += temp; ans += to_string(len);
                    temp = ""; len = 0;
                }
            }
        }
        if (temp != "") {
            ans += temp;
            ans += to_string(len);
        }
        cout << ans << endl;
    }
}