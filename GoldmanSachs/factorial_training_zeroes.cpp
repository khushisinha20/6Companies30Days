//leetcode.com/problems/factorial-trailing-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for (int i = 5; i <= n; i *= 5)
            result += (n / i);
        return result;
    }
};