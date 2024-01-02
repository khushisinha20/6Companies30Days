//leetcode.com/problems/random-flip-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> used;
    int rows;
    int cols;
    int total;
    
    Solution(int m, int n) {
        rows = m;
        cols = n;
        total = m * n;
    }
    
    vector<int> flip() {
        if (used.size() == total)
            return {};
        
        int index = rand() % total;
        while (used.count(index) > 0)
            index = ++index % total;
        
        used.insert(index);
        return {index / cols, index % cols};
    }
    
    void reset() {
        used.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
