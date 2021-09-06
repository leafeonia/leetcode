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
    int sum;
    
    void inorder(TreeNode* root, int l, int r) {
        if (!root) return;
        if (l <= root->val && root->val <= r) sum += root->val;
        inorder(root->left, l, r);
        inorder(root->right, l, r);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return sum;
    }
};