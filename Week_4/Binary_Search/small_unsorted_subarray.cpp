// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int i=0, j=nums.size()-1;
        while (i < nums.size()) {
            if (temp[i] == nums[i]) {
                i += 1;
            } else {
                break;
            }
        }
        while (j > i) {
            if (temp[j] == nums[j]) {
                j -= 1;
            } else {
                break;
            }
        }
        if (i == j) {
            return 0;
        } else {
            return j-i+1;
        }
    }
};