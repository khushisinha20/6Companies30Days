// https://leetcode.com/problems/map-of-highest-peak/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    queue<pair<int, int>> getWaterCells(vector<vector<int>>& isWater, vector<vector<int>>& height) {
        queue<pair<int, int>> cells;
        for (int row = 0; row < isWater.size(); ++row) {
            for (int col = 0; col < isWater[row].size(); ++col) {
                if (isWater[row][col] == 1) {
                    height[row][col] = 0;
                    cells.push({row, col});
                }
            }
        }
        return cells;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> cells = getWaterCells(isWater, height);

        while (!cells.empty()) {
            int size = cells.size();
            while (size--) {
                int row = cells.front().first;
                int col = cells.front().second;
                cells.pop();

                vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for (auto& neighbor: neighbors) {
                    int newRow = row + neighbor.first;
                    int newCol = col + neighbor.second;

                    if (newRow >= 0 and newRow < m and newCol >= 0 and newCol < n and height[newRow][newCol] == -1) {
                        height[newRow][newCol] = height[row][col] + 1;
                        cells.push({newRow, newCol});
                    }
                }
            }
        }

        return height;
    }
};
