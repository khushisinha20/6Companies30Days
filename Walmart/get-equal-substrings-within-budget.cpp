// leetcode.com/problems/get-equal-substrings-within-budget/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        int start = 0;
        int cost = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            cost += abs(s[end] - t[end]);
            if (cost <= maxCost)
                maxLength = max(maxLength, end - start + 1);
            while (cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                ++start;
            }
        }
        
        return maxLength;
    }
};
