// leetcode.com/problems/number-of-people-aware-of-a-secret/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1, 0);
        const int MOD = 1000000007;
        
        long long numberOfPeopleSharingSecret = 0;
        long long result = 0;
        dp[1] = 1;
        
        for (int day = 2; day <= n; ++day) {
            long long numberOfNewPeopleSharingSecret = dp[max(day - delay, 0)];
            long long numberOfPeopleForgettingSecret = dp[max(day - forget, 0)];
            numberOfPeopleSharingSecret += (numberOfNewPeopleSharingSecret - numberOfPeopleForgettingSecret) % MOD;
            dp[day] = numberOfPeopleSharingSecret % MOD;
        }
        
        for (int i = n - forget + 1; i <= n; ++i)
            result = (result + dp[i]) % MOD;
        
        return result;
    }
};
