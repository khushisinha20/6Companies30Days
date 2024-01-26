//leetcode.com/problems/construct-the-longest-new-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans = 0;
        if (x > y) {
            ans += z;
            ans += y + 1;
            ans += y;
        } else if (y > x) {
            ans += z;
            ans += x + 1;
            ans += x;
        } else {
            ans += z;
            ans += 2 * x;
        }
        
        return ans * 2;
    }
};
