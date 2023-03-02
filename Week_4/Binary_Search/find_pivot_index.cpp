// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector <int> pref;
        vector <int> suff;
        int x = 1;
        for (int i=0; i<n; i++) {
            x += nums[i];
            pref.push_back(x);
        }
        x = 1;
        for (int i=n-1; i>=0; i--) {
            x += nums[i];
            suff.push_back(x);
        }
        reverse(suff.begin(), suff.end());
        int ans = -1;
        for (int i=0; i<n; i++) {
            if (pref[i] == suff[i]) {
                ans = i; break;
            }
        }
        return ans;
    }
};