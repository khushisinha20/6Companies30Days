//leetcode.com/problems/top-k-frequent-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparator {
        bool operator() (pair<int, string>& a, pair<int, string>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };
    
    unordered_map<string, int> getFrequencyOfWords(vector<string>& words) {
        unordered_map<string, int> frequency;
        for (string& word: words)
            ++frequency[word];
        return frequency;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequencyMap = getFrequencyOfWords(words);
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> minHeap;
        
        for (auto& entry: frequencyMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
