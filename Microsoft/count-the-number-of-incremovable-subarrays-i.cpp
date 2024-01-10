//leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIncremovable(vector<int>& nums, int start, int end) {
        vector<int> auxiliary;
        for (int i = 0; i < start; ++i)
            auxiliary.push_back(nums[i]);
        
        for (int i = end + 1; i < nums.size(); ++i)
            auxiliary.push_back(nums[i]);
        
        for (int i = 1; i < auxiliary.size(); ++i)
            if (auxiliary[i - 1] >= auxiliary[i])
                return false;
        
        return true;
    }
    
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        
        for (int start = 0; start < nums.size(); ++start) {
            for (int end = start; end < nums.size(); ++end) {
                if (isIncremovable(nums, start, end))
                    ++ans;
            }
        }
        
        return ans;
    }
};
