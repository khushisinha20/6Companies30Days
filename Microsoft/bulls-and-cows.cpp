//leetcode.com/problems/bulls-and-cows/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getBulls(string& secret, string& guess) {
        int bulls = 0;
        for (int i = 0; i < secret.length(); ++i)
            if (secret[i] == guess[i])
                ++bulls;
        return bulls;
    }
    
    int getCows(string& secret, string& guess) {
        int cows = 0;
        vector<int> freqInSecret(10, 0);
        vector<int> freqInGuess(10, 0);
        
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i])
                continue;
            ++freqInSecret[secret[i] - '0'];
            ++freqInGuess[guess[i] - '0'];
        }
        
        for (int i = 0; i < 10; ++i)
            cows += min(freqInSecret[i], freqInGuess[i]);
        return cows;
    }
    
    string getHint(string secret, string guess) {
        string hint = to_string(getBulls(secret, guess)) + 'A' + to_string(getCows(secret, guess)) + 'B';
        return hint;
    }
};
