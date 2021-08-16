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
    TreeNode* prev;
    TreeNode* big;
    TreeNode* small;
    
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        if (prev && prev->val > root->val) {
            if (!big) big = prev;
            small = root;
        }
        prev = root;
        inOrder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        prev = small = big = NULL;
        inOrder(root);
        int val  = small->val;
        small->val = big->val;
        big->val = val;
    }
};