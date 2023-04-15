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
        int n, k; cin >> n >> k;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int heap_size = (n == k) ? k : k+1;
        priority_queue<int, vi, greater<int>> pq;
        // Insert first k+1 items
        for (int i=0; i<heap_size; i++) {
            pq.push(arr[i]);
        }
        int index = 0;
        for (int i=k+1; i<n; i++) {
            arr[index++] = pq.top();
            pq.pop(); pq.push(arr[i]);
        }
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
        for (auto i: arr) {
            cout << i << " ";
        }
    }
}