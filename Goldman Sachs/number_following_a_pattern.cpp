//www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string S){
        string pattern = S;
        stack<int> nums;
        string result;
        
        for (int i = 0; i <= pattern.length(); ++i) {
            nums.push(i + 1);
            if (i == pattern.length() or pattern[i] == 'I') {
                while (!nums.empty()) {
                    result += to_string(nums.top());
                    nums.pop();
                }
            }
        }
        
        return result;
    }
};

