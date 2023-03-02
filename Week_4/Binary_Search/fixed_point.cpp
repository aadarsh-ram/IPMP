// https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define vi vector<int>
#define pb push_back

using namespace std;

int binarySearch(vi arr, int low, int high) {
    if (high >= low) {
        int mid = (low + high) / 2;
        if (mid == arr[mid]) {
            return mid;
        }
        int res = -1;
        if (mid+1 <= arr[high]) {
            res = binarySearch(arr, (mid + 1), high);
        }
        if (res != -1) {
            return res;
        }
        if (mid-1 >= arr[low]) {
            return binarySearch(arr, low, (mid - 1));
        }
    }
    return -1;
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
        cout << binarySearch(arr, 0, n-1) << endl;
    }
}