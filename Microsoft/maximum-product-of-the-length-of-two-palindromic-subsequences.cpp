//leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromicSubsequence(string& text1) {
        string text2(text1.rbegin(), text1.rend());
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if (i == 0 or j == 0)
                    dp[i][j] = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
    int maxProduct(string s) {
        int n = s.length();
        int maxProduct = 0;

        for (int mask = 0; mask < (1 << n); ++mask) {
            string subsequence1;
            string subsequence2;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i))
                    subsequence1 += s[i];
                else
                    subsequence2 += s[i];
            }
            
            int lpsInSubsequence1 = longestPalindromicSubsequence(subsequence1);
            int lpsInSubsequence2 = longestPalindromicSubsequence(subsequence2);
            
            maxProduct = max(maxProduct, lpsInSubsequence1 * lpsInSubsequence2);
        }
        
        return maxProduct;
    }
};
