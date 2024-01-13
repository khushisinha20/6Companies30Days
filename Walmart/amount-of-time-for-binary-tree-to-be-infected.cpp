//leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

#include <bits.stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* node, unordered_map<int, unordered_set<int>>& graph) {
        if (!node)
            return;
        
        if (node -> left) {
            graph[node -> val].insert(node -> left -> val);
            graph[node -> left -> val].insert(node -> val);
        }
        
        if (node -> right) {
            graph[node -> val].insert(node -> right -> val);
            graph[node -> right -> val].insert(node -> val);
        }
        
        dfs(node -> left, graph);
        dfs(node -> right, graph);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> graph;
        dfs(root, graph);
        queue<int> bfsQueue;
        unordered_set<int> visited;
        visited.insert(start);
        bfsQueue.push(start);
        int minutes = -1;
        
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            for (int i = 0; i < size; ++i) {
                int currentNode = bfsQueue.front();
                bfsQueue.pop();
                
                for (auto& neighbor: graph[currentNode]) {
                    if (!visited.count(neighbor)) {
                        bfsQueue.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            ++minutes;
        }
        
        return minutes;
    }
};
