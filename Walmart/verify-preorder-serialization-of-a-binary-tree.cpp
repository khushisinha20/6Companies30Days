//leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> strip(string& preorder) {
        vector<string> nodes;
        int i = 0;
        string currentNode;
        
        while (i < preorder.length()) {
            while (i < preorder.length() and preorder[i] != ',') {
                currentNode += preorder[i];
                ++i;
            }
            nodes.push_back(currentNode);
            currentNode = "";
            ++i;
        }
        
        return nodes;
    }
    
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        vector<string> nodes = strip(preorder);
        
        for (string& node: nodes) {
            --vacancy;
            
            if (vacancy < 0)
                return false;
            
            if (node != "#")
                vacancy += 2;
        }
        
        return vacancy == 0;
    }
};
