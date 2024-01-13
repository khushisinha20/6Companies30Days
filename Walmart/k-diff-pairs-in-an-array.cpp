//leetcode.com/problems/k-diff-pairs-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> distinct;
        for (int num : nums)
            ++distinct[num];

        int pairs = 0;

        for (auto& entry : distinct) {
            int num = entry.first;
            if (k != 0) {
                if (distinct.find(num - k) != distinct.end())
                    ++pairs;
                if (distinct.find(num + k) != distinct.end())
                    ++pairs;
            } else {
                if (distinct[num] > 1)
                    pairs += 2;
            }
        }

        return pairs / 2;
    }
};

