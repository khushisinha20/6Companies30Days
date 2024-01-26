//leetcode.com/problems/short-encoding-of-words/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        
        int result = 0;
        unordered_set<string> suffixes;
        
        for (const string& word: words) {
            if (suffixes.find(word) == suffixes.end()) {
                result += word.length() + 1;
                for (int i = 0; i < word.length(); ++i)
                    suffixes.insert(word.substr(i));
            }
        }
        
        return result;
    }
};