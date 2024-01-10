//leetcode.com/problems/repeated-dna-sequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> sequenceMap;
        
        if (s.length() < 10)
            return result;
        
        for (int i = 0; i <= s.length() - 10; ++i) {
            string sequence = s.substr(i, 10);
            if (sequenceMap.find(sequence) == sequenceMap.end())
                sequenceMap[sequence] = 1;
            else {
                if (sequenceMap[sequence] == 1) 
                    result.push_back(sequence);
                ++sequenceMap[sequence];
            }
        }
        
        return result;
    }
};
