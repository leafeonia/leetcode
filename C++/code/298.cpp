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
    int ans = 0;
    
    void dfs(TreeNode* root, int val, int len) {
        if (!root) return;
        len = root->val == val + 1 ? len + 1 : 1;
        ans = max(ans, len);
        dfs(root->left, root->val, len);
        dfs(root->right, root->val, len);
    }
    
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        dfs(root, INT_MIN, 0);
        return ans;
    }
};