// https://leetcode.com/problems/search-in-rotated-sorted-array

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchUtil(vector<int>&arr, int l, int r, int key) {
        if (l > r) return -1;
        int mid = (l+r)/2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[l] <= arr[mid]) {
            if (key >= arr[l] && key <= arr[mid]) {
                return searchUtil(arr, l, mid-1, key);
            }
            return searchUtil(arr, mid+1, r, key);
        }
        if (key >= arr[mid] && key <= arr[r]) {
            return searchUtil(arr, mid+1, r, key);
        }
        return searchUtil(arr, l, mid-1, key);
    }
    int search(vector<int>& nums, int target) {
        return searchUtil(nums, 0, nums.size()-1, target);
    }
};