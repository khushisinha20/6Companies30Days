//leetcode.com/problems/shopping-offers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getKey(vector<int>& needs) {
        string needsStr;
        for (auto& need: needs)
            needsStr += to_string(need);
        return needsStr;
    }
    
    int directPurchase(vector<int>& price, vector<int>& needs) {
        int cost = 0;
        
        for (int i = 0; i < needs.size(); ++i) 
            cost += price[i] * needs[i];
        
        return cost;
    }
    
    int shoppingOffersHelper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, unordered_map<string, int>& memo) {
        string key = getKey(needs);
        
        if (memo.find(key) != memo.end())
            return memo[key];
        
        int cost = directPurchase(price, needs);
        
        for (auto& offer: special) {
            vector<int> updatedNeeds(needs.begin(), needs.end());
            bool canUseOffer = true;
            
            for (int i = 0; i < needs.size(); ++i) {
                updatedNeeds[i] -= offer[i];
                if (updatedNeeds[i] < 0) {
                    canUseOffer = false;
                    break;
                }
            }
            
            if (canUseOffer)
                cost = min(cost, offer.back() + shoppingOffersHelper(price, special, updatedNeeds, memo));
        }
        
        return memo[key] = cost;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return shoppingOffersHelper(price, special, needs, memo);
    }
};
