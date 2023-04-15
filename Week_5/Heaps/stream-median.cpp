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
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        priority_queue<int> s;
        priority_queue<int, vi, greater<int>> g;
        for (int i=0; i<n; i++) {
            s.push(arr[i]);
            g.push(s.top());
            s.pop();

            if (s.size() < g.size()) {
                s.push(g.top());
                g.pop();
            }
            if (s.size() == g.size()) {
                cout << (double)((s.top()*1.0 + g.top()*1.0))/2 << endl;
            } else {
                cout << s.top() << endl;
            }
        }
    }
}