// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l=0, r=nums.size()-1;
        int mid;
        while (l <= r) {
            mid = (l+r)/2;
            if ((mid == 0 || target > nums[mid-1]) && (nums[mid] == target)) {
                ans.push_back(mid); break;
            } else if (target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans.size() == 0) ans.push_back(-1);
        l=0, r=nums.size()-1;
        while (l <= r) {
            mid = (l+r)/2;
            cout << mid << endl;
            if ((mid == nums.size()-1 || target < nums[mid+1]) && (nums[mid] == target)) {
                ans.push_back(mid); break;
            } else if (target >= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans.size() == 1) ans.push_back(-1);
        return ans;
    }
};