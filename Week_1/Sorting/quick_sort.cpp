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

int partition(vi &arr, int low, int high) {
    int pivot = arr[high];
    int fp = low-1;

    for (int i=low; i<high; i++) {
        if (arr[i] < pivot) {
            fp++; swap(&arr[i], &arr[fp]);
        }
    }
    swap(&arr[fp+1], &arr[high]);
    return fp+1;
}

void quickSort(vi &arr, int low, int high) {
    if (low < high) {
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv-1);
        quickSort(arr, piv+1, high);
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
        quickSort(arr, 0, n-1);
        for (auto &i: arr) cout << i << " ";
    }
}