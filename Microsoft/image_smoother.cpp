// https://leetcode.com/problems/image-smoother/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        
        vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        auto liesInsideImage = [&](int newRow, int newCol) {
            return newRow >= 0 and newRow < rows and newCol >= 0 and newCol < cols;
        };
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int sum = 0;
                int validCellCount = 0;
                
                for (auto& direction: directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];
                    
                    if (liesInsideImage(newRow, newCol)) {
                        sum += img[newRow][newCol];
                        ++validCellCount;
                    }
                }
                
                result[row][col] = sum / validCellCount;
            }
        }
        
        return result;
    }
};
