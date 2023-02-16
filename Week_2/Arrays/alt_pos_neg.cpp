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
        // Make positive numbers and negative numbers separate
        int fp = -1;
        for (int j=0; j<n; j++) {
            if (arr[j] < 0) {
                fp++;
                swap(&arr[fp], &arr[j]);
            }
        }
        int pos = fp+1, neg = 0;
        while (pos < n && neg < pos && arr[neg] < 0) {
            swap(&arr[neg], &arr[pos]);
            neg+=2; pos++;
        }
        for (auto i: arr) cout << i << " ";
    }
}