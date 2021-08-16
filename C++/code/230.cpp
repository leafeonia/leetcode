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
    int answer = 0;
    
    void inorder(TreeNode* root, int& n, int k) {
        if (!root || n > k) return;
        inorder(root->left, n, k);
        n++;
        if (n == k) answer = root->val;
        inorder(root->right, n, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        inorder(root, n, k);
        return answer;
    }
};