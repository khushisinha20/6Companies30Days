// leetcode.com/problems/rotate-function/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getInitialF(vector<int>& nums) {
        int F = 0;
        for (int i = 0; i < nums.size(); ++i)
            F += i * nums[i];
        return F;
    }
    
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int F = getInitialF(nums);
        int maxF = F;
        
        int last = n - 1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int i = 1; i < n; ++i) {
            F = F + (sum - (n * nums[last]));
            maxF = max(maxF, F);
            last = (last - 1 + n) % n;
        }
        
        return maxF;
    }
};
