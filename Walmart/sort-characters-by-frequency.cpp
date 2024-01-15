//leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, int> getFrequency(string& s) {
        unordered_map<char, int> frequency;
        for (int i = 0; i < s.length(); ++i)
            ++frequency[s[i]];
        return frequency;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> frequency = getFrequency(s);
        string result;
        priority_queue<pair<int, char>> maxHeap;
        
        for (auto& freq: frequency)
            maxHeap.push({freq.second, freq.first});
        
        while (!maxHeap.empty()) {
            result += string(maxHeap.top().first, maxHeap.top().second);
            maxHeap.pop();
        }
        
        return result;
    }
};
