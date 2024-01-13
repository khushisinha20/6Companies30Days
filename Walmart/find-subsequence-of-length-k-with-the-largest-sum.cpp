//leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < nums.size(); ++i)
            maxHeap.push({nums[i], i});
        
        vector<int> result(k);
        
        for (int i = 0; i < k; ++i) {
            result[i] = maxHeap.top().second;
            maxHeap.pop();
        }
        
        sort(result.begin(), result.end());
        for (auto& num: result)
            num = nums[num];
        
        return result;
    }
};
