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
    typedef pair<int, int> pi; // first: max subtree value without current node value; second: max subtree value considering current node value
    
    pi dfs(TreeNode* root) {
        if (!root) return {0, 0};
        pi left = dfs(root->left);
        pi right = dfs(root->right);
        return {max(left.first, left.second) + max(right.first, right.second), left.first + right.first + root->val};
    }
        
    int rob(TreeNode* root) {
        pi ans = dfs(root);
        return max(ans.first, ans.second);
    }
};