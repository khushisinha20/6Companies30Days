// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rects;
    int numPoints;
    vector<int> cumulativeSumOfAreas;
    
    int getTotalPoints(vector<int>& rectangle) {
        return (rectangle[2] - rectangle[0] + 1) * (rectangle[3] - rectangle[1] + 1);
    }
    
    int getPointIndex(int randomPoint) {
        int low = 0;
        int high = cumulativeSumOfAreas.size() - 1;
        int index = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cumulativeSumOfAreas[mid] > randomPoint) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return index;
    }
    
    Solution(vector<vector<int>>& rects) {
        this -> rects = rects;
        numPoints = 0;
        
        for (auto& rect: rects) {
            numPoints += getTotalPoints(rect);
            cumulativeSumOfAreas.push_back(numPoints);
        }
    }
    
    vector<int> pick() {
        int randomPoint = rand() % numPoints;
        int pointIndex = getPointIndex(randomPoint);
        
        vector<int> rectangle = rects[pointIndex];
        int horizontalPoints = rectangle[2] - rectangle[0] + 1;
        int verticalPoints = rectangle[3] - rectangle[1] + 1;
        int pointsInRectangle = getTotalPoints(rectangle);
        int start = cumulativeSumOfAreas[pointIndex] - pointsInRectangle;
        int offset = randomPoint - start;
        
        return {rectangle[0] + offset % horizontalPoints, rectangle[1] + offset / horizontalPoints};
    }
};
