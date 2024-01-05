//leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char DELIMETER = '-';
    const int MOD = 1e9 + 7;
    unordered_map<string, int> dp;
    
    string getKey(int position, int stepsLeft) {
        return to_string(stepsLeft) + DELIMETER + to_string(position);
    }
    
    int helper(int currentPos, int endPos, int stepsLeft) {
        if (stepsLeft == 0)
            return currentPos == endPos;
        
        string key = getKey(currentPos, stepsLeft);
        if (dp.find(key) != dp.end()) 
            return dp[key];
        
        int ways = 0;
        if (abs(endPos - currentPos) <= stepsLeft) {
            ways = (ways + helper(currentPos + 1, endPos, stepsLeft - 1)) % MOD;
            ways = (ways + helper(currentPos - 1, endPos, stepsLeft - 1)) % MOD;
        }
        
        return dp[key] = ways % MOD;
    }
    
    int numberOfWays(int startPos, int endPos, int k) {
        return helper(startPos, endPos, k);
    }
};
