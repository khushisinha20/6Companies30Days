//leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinations;

    void backtrack(int k, int n, int currentNumber, vector<int>& currentCombination) {
        if (k == 0 && n == 0) {
            combinations.push_back(currentCombination);
            return;
        }

        if (k == 0)
            return;

        if (n == 0)
            return;

        if (currentNumber == 10)
            return;

        currentCombination.push_back(currentNumber);
        backtrack(k - 1, n - currentNumber, currentNumber + 1, currentCombination);
        currentCombination.pop_back();
        backtrack(k, n, currentNumber + 1, currentCombination);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currentCombination;
        backtrack(k, n, 1, currentCombination);
        return combinations;
    }
};
