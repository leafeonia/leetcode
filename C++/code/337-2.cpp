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
    unordered_map<TreeNode*, int> mp;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        if (mp[root]) return mp[root];
        int val = root->val;
        if (root->left) val += dfs(root->left->left) + dfs(root->left->right);
        if (root->right) val += dfs(root->right->left) + dfs(root->right->right);
        val = max(val, dfs(root->left) + dfs(root->right));
        mp[root] = val;
        return val;
    }
        
    int rob(TreeNode* root) {
        return dfs(root);
    }
};