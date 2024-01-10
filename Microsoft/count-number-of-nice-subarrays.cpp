//leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAuxiliaryArray(vector<int>& nums) {
        vector<int> auxiliary;
        for (auto& num: nums)
            auxiliary.push_back(num & 1);
        return auxiliary;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int niceSubarrays = 0;
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1;
        int currentSum = 0;
        vector<int> auxiliary = getAuxiliaryArray(nums);
        
        for (auto& num: auxiliary) {
            currentSum += num;
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end())
                niceSubarrays += prefixSumMap[currentSum - k];
            ++prefixSumMap[currentSum];
        }
        
        return niceSubarrays;
    }
};
