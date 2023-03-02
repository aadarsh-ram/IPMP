// https://leetcode.com/problems/merge-sorted-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (nums1.size() > m) nums1.pop_back();
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < m+n && ptr2 < n) {
            if (ptr1 >= nums1.size() || ptr2 >= n) break;
            if (nums1[ptr1] <= nums2[ptr2]) {
                ptr1 += 1;
            } else {
                nums1.insert(nums1.begin()+ptr1, nums2[ptr2]);
                ptr1 += 1; ptr2 += 1;
            }
        }
        while (ptr2 < n) {
            nums1.insert(nums1.begin()+ptr1, nums2[ptr2]);
            ptr1 += 1; ptr2 += 1;
        }
    }
};