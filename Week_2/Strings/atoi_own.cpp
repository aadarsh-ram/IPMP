#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int myatoi(string &s) {
    int sign = 1, base = 0, i = 0;
    while (s == " ") i++;
    if (s[i] == '-' || s[i] == '+') {
        if (s[i++] == '-') sign = -1;
        else sign = 1;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        if (base > INT_MAX/10 || (base == INT_MAX/10 && s[i]-'0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base = 10*base + (s[i++] - '0');
    }
    return base*sign;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string s; cin >> s;
        cout << myatoi(s) << endl;
    }
}