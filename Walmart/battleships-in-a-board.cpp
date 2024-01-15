//leetcode.com/problems/battleships-in-a-board/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' and (i == 0 or board[i - 1][j] != 'X') and (j == 0 or board[i][j - 1] != 'X'))
                    ++ans;
            }
        }
        
        return ans;
    }
};
