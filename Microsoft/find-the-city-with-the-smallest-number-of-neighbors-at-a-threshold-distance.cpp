//leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillDistances(vector<vector<int>>& distances, vector<vector<int>>& edges) {
        for (auto& edge: edges) {
            distances[edge[0]][edge[1]] = edge[2];
            distances[edge[1]][edge[0]] = edge[2];
        }
        
        for (int i = 0; i < distances.size(); ++i)
            distances[i][i] = 0;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int> (n, INT_MAX));
        int validCities = 0;
        int leastValidCity = n;
        int cityWithLeastNeighbors = -1;
        
        fillDistances(distance, edges);
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (distance[i][k] == INT_MAX or distance[j][k] == INT_MAX)
                        continue;
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        for (int currentCity = 0; currentCity < n; ++currentCity) {
            validCities = 0;
            for (int adjacentCity = 0; adjacentCity < n; ++adjacentCity) {
                if (distance[currentCity][adjacentCity] <= distanceThreshold)
                    ++validCities;
            }
            
            if (validCities <= leastValidCity) {
                leastValidCity = validCities;
                cityWithLeastNeighbors = currentCity;
            }
        }
        
        return cityWithLeastNeighbors;
    }
};
