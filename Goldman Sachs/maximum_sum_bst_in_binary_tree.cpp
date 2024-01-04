//leetcode.com/problems/maximum-sum-bst-in-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct TreeInfo {
    int sum;
    int maxVal;
    int minVal;
    bool isBST;

    TreeInfo(int sum, int maxVal, int minVal, bool isBST) {
        this->sum = sum;
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int maxSum = 0;

    TreeInfo dfs(TreeNode* node) {
        if (!node)
            return TreeInfo(0, INT_MIN, INT_MAX, true);

        TreeInfo left = dfs(node->left);
        TreeInfo right = dfs(node->right);

        int sum = left.sum + right.sum + node->val;
        int maxValue = max(node->val, max(left.maxVal, right.maxVal));
        int minValue = min(node->val, min(left.minVal, right.minVal));
        bool isBST = left.isBST and right.isBST and (node->val > left.maxVal) and (node->val < right.minVal);

        if (isBST)
            maxSum = max(maxSum, sum);

        return TreeInfo(sum, maxValue, minValue, isBST);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

