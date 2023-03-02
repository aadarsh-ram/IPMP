// https://leetcode.com/problems/find-peak-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while (l<r) {
            int mid = (l+r)/2;
            if (nums[mid] > nums[mid+1]) r = mid;
            else l = mid+1;
        }
        return l;
    }
};