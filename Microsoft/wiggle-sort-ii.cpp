//leetcode.com/problems/wiggle-sort-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void threeWayPartition(vector<int>& nums, int median) {
        int start = 0;
        int mid = 0;
        int end = nums.size() - 1;
        
        while (mid <= end) {
            if (nums[mid] < median) {
                swap(nums[start], nums[mid]);
                ++start;
                ++mid;
            } else if (nums[mid] == median)
                ++mid;
            else {
                swap(nums[mid], nums[end]);
                --end;
            }
        }
    }
    
    int getMedian(vector<int>& nums) {
        int mid = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        return nums[mid];
    }
    
    void wiggleSort(vector<int>& nums) {
        int median = getMedian(nums);
        threeWayPartition(nums, median);
        
        int n = nums.size();
        int mid = n / 2;
        
        vector<int> result(n);
        int smaller = mid;
        if (n % 2 == 0)
            smaller = mid - 1;
        int larger = n - 1;
        
        for (int i = 0; i < n; i += 2)
            result[i] = nums[smaller--];
        
        for (int i = 1; i < n; i += 2)
            result[i] = nums[larger--];
        
        nums = result;
    }
};
