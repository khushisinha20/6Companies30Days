//leetcode.com/problems/largest-divisible-subset/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int endIndex = -1;
        int maxLength = -1;
        
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    
                    if (dp[i] > maxLength) {
                        maxLength = dp[i];
                        endIndex = i;
                    }
                }
            }
        }
        
        vector<int> result;
        while (endIndex != -1) {
            result.push_back(nums[endIndex]);
            endIndex = parent[endIndex];
        }
        
        reverse(result.begin(), result.end());
        
        if (result.empty())
            return {nums[0]};
        
        return result;
    }
};
