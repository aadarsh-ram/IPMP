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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        int xor_total = 0;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            xor_total ^= arr[i];
        }
        int rightmost_set_bit = xor_total & ~(xor_total-1);
        /*
        Numbers are xor'ed based on right-most set bit (rsb).
        The current total xor must be created by two numbers:
            - One having set bit at position of rsb
            - One not having a set bit at position rsb 
        */
       int x = 0, y = 0;
       for (int i=0; i<n; i++) {
            if (arr[i] & rightmost_set_bit) x ^= arr[i];
            else y ^= arr[i];
       }
       cout << x << " " << y << endl;
    }
}