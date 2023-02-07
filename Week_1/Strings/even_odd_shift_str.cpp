#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void cycleLeaderAlgo(string &s, int shift, int n) {
    for (int i=1; i<n; i*=3) {
        int j = i;
        char item = s[j+shift];
        while (1) {
            if (j % 2 != 0) {
                j = n/2 + j/2;
            } else {
                j /= 2;
            }
            char temp = s[j+shift];
            s[j+shift] = item;
            item = temp;
            if (j == i) break;
        }
    }
}

void solution(string &s) {
    int rem_len = s.length();
    int shift = 0;
    while (rem_len) {
        int k = 0;
        while (pow(3, k)+1 <= rem_len) k++;
        int curr_len = pow(3, k-1) + 1;
        rem_len -= curr_len;
        cycleLeaderAlgo(s, shift, curr_len);

        // STL reverse uses s.end(), which points to end of array+1
        
        reverse(s.begin()+(shift/2), s.begin()+(shift)); // Reverse 2nd half of 1st substring
        reverse(s.begin()+(shift), s.begin()+(shift+(curr_len/2))); // Reverse 1st half of 2nd substring
        reverse(s.begin()+(shift/2), s.begin()+(shift+(curr_len/2))); // Reverse entire substring
        shift += curr_len;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        string s; cin >> s;
        solution(s);
        cout << s;
    }
}