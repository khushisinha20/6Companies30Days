//leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillAvailability(unordered_map<int, int>& availabilityMap, vector<int>& nums) {
        for (auto num: nums)
            ++availabilityMap[num];
    }
    
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> availabilityMap;
        unordered_map<int, int> vacancyMap;
        fillAvailability(availabilityMap, nums);
        
        for (auto num: nums) {
            if (availabilityMap[num] <= 0)
                continue;
            else if (availabilityMap[num] > 0 && vacancyMap[num] > 0) {
                --availabilityMap[num];
                --vacancyMap[num];
                ++vacancyMap[num + 1];
            } else if (availabilityMap[num] > 0 && availabilityMap[num + 1] > 0 && availabilityMap[num + 2] > 0) {
                --availabilityMap[num];
                --availabilityMap[num + 1];
                --availabilityMap[num + 2];
                ++vacancyMap[num + 3];
            } else
                return false;
        }
        return true;
    }
};