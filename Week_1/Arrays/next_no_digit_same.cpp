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
        vi v;
        while(n > 0) {
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin(), v.end());
        int br = -1;
        for (int i = v.size()-1; i > 0; i--) {
            if (v[i] > v[i-1]) {
                br = i; break;
            }
        }
        if (br == -1) {
            cout << "Not Possible" << endl;
        }
        else if (br == v.size()-1) {    
            reverse(v.begin()+v.size()-2, v.end());
            for (int i=0; i<v.size(); i++) {
                cout << v[i];
            }
        }
        else {
            for (int j = v.size()-1; j >= br; j--) {
                if (v[br-1] < v[j]) {
                    int temp = v[br-1];
                    v[br-1] = v[j];
                    v[j] = temp;
                    break;
                }
            }
            reverse(v.begin()+br, v.end());
            for (int i=0; i<v.size(); i++) {
                cout << v[i];
            }
        }
    }
}