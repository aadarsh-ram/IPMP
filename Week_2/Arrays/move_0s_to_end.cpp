#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b;
    *b = temp;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; t=1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int left = 0;
        for (int i=0; i<n; i++) {
            if (arr[i] != 0) {
                swap(&arr[i], &arr[left]);
                left++;
            }
        }
        for (auto i: arr) cout << i << " ";
    }
}