// https://leetcode.com/problems/majority-element

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2]; // Majority element will stay in middle
    }
};