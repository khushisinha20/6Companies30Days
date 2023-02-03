//leetcode.com/problems/number-of-boomerangs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distance(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if (points.size() < 3)
            return 0;
        
        int boomerangs = 0;
        
        for (auto point1: points) {
            unordered_map<int, int> distanceFrequency;
            for (auto point2: points) {
                if (point1 == point2)
                    continue;
                ++distanceFrequency[distance(point1, point2)];
            }
            for (auto freq: distanceFrequency)
                if (freq.second > 1)
                    boomerangs += (freq.second * (freq.second - 1));
        }
        
        return boomerangs;
    }
};