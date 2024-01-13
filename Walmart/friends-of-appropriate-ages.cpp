//leetcode.com/problems/friends-of-appropriate-ages/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int ageA, int ageB) {
        return !(ageB <= 0.5 * ageA + 7 || ageB > ageA || (ageB > 100 && ageA < 100));
    }
    
    int numFriendRequests(vector<int>& ages) {
        vector<int> ageCount(121, 0);
        
        for (int age: ages)
            ++ageCount[age];
        
        int requests = 0;
        
        for (int ageA = 1; ageA <= 120; ++ageA) {
            for (int ageB = 1; ageB <= 120; ++ageB) {
                int countA = ageCount[ageA];
                int countB = ageCount[ageB];
                
                if (isValid(ageA, ageB)) {
                    requests += countA * countB;
                    if (ageA == ageB)
                        requests -= countA;
                }
            }
        }
        
        return requests;
    }
};
