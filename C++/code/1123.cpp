/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (!root) return {0, nullptr};
        auto left = solve(root->left);
        auto right = solve(root->right);
        if (left.first > right.first) return {left.first + 1, left.second};
        if (left.first < right.first) return {right.first + 1, right.second};
        else return {left.first + 1, root};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};