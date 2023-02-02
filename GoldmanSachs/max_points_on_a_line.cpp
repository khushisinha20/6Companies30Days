//leetcode.com/problems/max-points-on-a-line/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxFrequency = INT_MIN;
        
        if (points.size() < 2)
            return points.size();
        
        for (auto point1: points) {
            unordered_map<double, int> slopeFrequency;
            for (auto point2: points) {
                if (point2 == point1)
                    continue;
                
                double slope = 0;
                if (point1[0] == point2[0]) 
                    slope = numeric_limits<double> :: max();
                else
                    slope = (double)(point2[1] - point1[1]) / (double)(point2[0] - point1[0]);
                
                ++slopeFrequency[slope];
                
                if (slopeFrequency[slope] > maxFrequency)
                    maxFrequency = slopeFrequency[slope];
            }
        }
        
        return maxFrequency + 1;
    }
};