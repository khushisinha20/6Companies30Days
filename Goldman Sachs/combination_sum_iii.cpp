// leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& combinations, vector<int>& currentCombination, int k, int n, int currentNumber) {
        if (k < 0 or n < 0)
            return;
        
        if (n == 0 and k == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        
        if (currentNumber <= 0)
            return;
        
        currentCombination.push_back(currentNumber);
        backtrack(combinations, currentCombination, k - 1, n - currentNumber, currentNumber - 1);
        currentCombination.pop_back();
        backtrack(combinations, currentCombination, k, n, currentNumber - 1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        backtrack(combinations, currentCombination, k, n, 9);
        return combinations;
    }
};
