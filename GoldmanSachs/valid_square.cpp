//leetcode.com/problems/valid-square/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLength(vector<int>& side1, vector<int>& side2) {
        return (side1[0] - side2[0]) * (side1[0] - side2[0]) + (side1[1] - side2[1]) * (side1[1] - side2[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> lengths = {
            getLength(p1, p2),
            getLength(p1, p3),
            getLength(p1, p4),
            getLength(p2, p3),
            getLength(p2, p4),
            getLength(p3, p4),
        };
        
        unordered_map<int, int> lengthFrequency;
        
        for (auto& length: lengths) {
            if (length == 0) //to handle cases of duplicate coordinates
                return false;
            ++lengthFrequency[length];
        }
        
        if (lengthFrequency.size() != 2)
            return false;
        
        for (auto& freq: lengthFrequency)
            return freq.second == 2 || freq.second == 4;
        
        return false;
    }
};