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
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        v.push_back(root);
        dfs(root->right);
    }
    
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = v[mid];
        node->left = build(left, mid - 1);
        node->right = build(mid + 1, right);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return build(0, v.size() - 1); 
    }
    
    vector<TreeNode*> v;
};