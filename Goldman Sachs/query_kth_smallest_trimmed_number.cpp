//leetcode.com/problems/query-kth-smallest-trimmed-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string trim(string& num, int trimLength) {
        int n = num.length();
        return num.substr(n - trimLength, trimLength);
    }
    
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (auto& query: queries) {
            int k = query[0];
            int trimLength = query[1];
            priority_queue<pair<string, int>> maxHeap;
            
            for (int i = 0; i < nums.size(); ++i) {
                string num = nums[i];
                string trimmedNum = trim(num, trimLength);
                
                if (maxHeap.size() < k)
                    maxHeap.push({trimmedNum, i});
                else {
                    if (maxHeap.top().first > trimmedNum) {
                        maxHeap.pop();
                        maxHeap.push({trimmedNum, i});
                    }
                }
            }
            
            result.push_back(maxHeap.top().second);
        }
        
        return result;
    }
};
