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
    int t; t = 1;
    while (t--) {
        int n; cin >> n;
        vi arr(n);
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vi ans;
        for (int i=0; i<n-1; i++) {
            if (arr[i] < arr[i+1]) {
                if (ans.size() == 0) {
                    ans.pb(arr[i]); ans.pb(arr[i+1]);
                }
                else {
                    if (ans[1] < arr[i+1]) {
                        ans.pb(arr[i+1]);
                        break;
                    } else {
                        if (ans[0] < arr[i+1] && ans[1] > arr[i+1]) {
                            ans.pop_back();
                            ans.pb(arr[i+1]);
                        } else if (ans[0] > arr[i+1] && arr[1] > arr[i+1]) {
                            ans.pop_back();
                            ans.pop_back();
                            ans.push_back(arr[i]);
                            ans.push_back(arr[i+1]);
                        }
                    }
                }
            }
            else {
                if (ans.size() > 0) {
                    if (ans[0] < arr[i+1] && ans[1] > arr[i+1]) {
                        ans.pop_back();
                        ans.pb(arr[i+1]);
                    } else if (ans[0] > arr[i+1] && arr[1] > arr[i+1]) {
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(arr[i+1]);
                        ans.push_back(arr[i]);
                    }
                }
            }
        }
        if (ans.size() < 3) cout << "No elements found" << endl;
        else {
            for (int i=0; i<3; i++) {
                cout << ans[i] << " ";
            }
        }
    }
}