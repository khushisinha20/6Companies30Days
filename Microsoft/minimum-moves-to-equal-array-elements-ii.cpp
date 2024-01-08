//leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = n / 2;
        int minMoves = 0;
        
        for (auto& num: nums)
            minMoves += abs(num - nums[mid]);
        
        return minMoves;
    }
};
