//leetcode.com/problems/count-the-number-of-square-free-subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int power(int base, int exponent) {
        int result = 1;
        while (exponent) {
            if (exponent & 1)
                result = (result * 1ll * base) % MOD;
            base = (1ll * base * base) % MOD;
            exponent >>= 1;
        }
        
        return result % MOD;
    }
    
    int countSquareFreeSubsets(vector<vector<int>>& dp, vector<int>& masks, int index, int mask) {
        if (index >= masks.size())
            return mask != 0;
        
        if (dp[index][mask] != -1)
            return dp[index][mask];
        
        int notTake = countSquareFreeSubsets(dp, masks, index + 1, mask);
        int take = 0;
        
        if ((masks[index] & mask) == 0)
            take = countSquareFreeSubsets(dp, masks, index + 1, mask ^ masks[index]);
        
        return dp[index][mask] = (take + notTake) % MOD;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        unordered_set<int> nonPrimes = {4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28};
        vector<int> masksOfNums;
        int countOfOnes = 0;
        
        for (int num : nums) {
            if (num == 1)
                ++countOfOnes;
            else {
                if (!nonPrimes.count(num)) {
                    int mask = 0;
                    for (int i = 0; i < primes.size(); ++i) {
                        if (num % primes[i] == 0) 
                            mask ^= (1 << i);
                    }
                    masksOfNums.push_back(mask);
                }
            }
        }
        
        int maxIndex = masksOfNums.size();
        int maxMask = 1 << 10;
        vector<vector<int>> dp(maxIndex + 1, vector<int>(maxMask, -1));
        
        int ans = countSquareFreeSubsets(dp, masksOfNums, 0, 0);
        ans = (1ll * ans * power(2, countOfOnes) % MOD + power(2, countOfOnes) - 1 + MOD) % MOD;
        return ans;
    }
};


