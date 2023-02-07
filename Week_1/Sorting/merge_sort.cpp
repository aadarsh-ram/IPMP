#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

void merge(vi &arr, int p, int q, int r) {
    vi temp;
    int i=p, j=q+1;
    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= q) {
        temp.push_back(arr[i]); i++;
    }
    while (j <= r) {
        temp.push_back(arr[j]); j++;
    }
    for (int i=p; i <= r; i++) {
        arr[i] = temp[i-p];
    }
}

void mergeSort(vi &arr, int l, int r) {
    if (l < r) {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        mergeSort(arr, 0, n-1);
        for (auto &i: arr) cout << i << " ";
    }
}