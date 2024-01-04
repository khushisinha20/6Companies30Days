//leetcode.com/problems/k-divisible-elements-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> distinctSubarrays;
        int multiplesOfP = 0;

        for (int i = 0; i < nums.size(); ++i) {
            multiplesOfP = 0;
            vector<int> subarray;
            for (int j = i; j < nums.size(); ++j) {
                subarray.push_back(nums[j]);
                if (nums[j] % p == 0)
                    ++multiplesOfP;
                if (multiplesOfP > k)
                    break;
                distinctSubarrays.insert(subarray);
            }
        }

        return distinctSubarrays.size();
    }
};
