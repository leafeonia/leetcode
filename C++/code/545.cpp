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
    vector<int> ans;
    
    void dfs(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.push_back(root->val);
        TreeNode* left = root->left;
        while (left && (left->left || left->right)) {
            ans.push_back(left->val);
            if (left->left) left = left->left;
            else left = left->right;
        }
        if (root->left || root->right) dfs(root);
        TreeNode* right = root->right;
        stack<int> st;
        while (right && (right->left || right->right)) {
            st.push(right->val);
            if (right->right) right = right->right;
            else right = right->left;
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};