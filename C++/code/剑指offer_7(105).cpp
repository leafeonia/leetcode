/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int pos = find(inorder.begin(),inorder.end(),root->val) - inorder.begin();
        root->left = buildTree(preorder, inorder, 1, pos, 0, pos - 1);
        root->right = buildTree(preorder, inorder, pos + 1, preorder.size() - 1, pos + 1, preorder.size() - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight){
        if(preLeft > preRight || inLeft > inRight) return NULL;
        TreeNode* ret = new TreeNode(preorder[preLeft]);
        int pos = find(inorder.begin(),inorder.end(),ret->val) - inorder.begin();
        ret->left = buildTree(preorder, inorder, preLeft + 1, preRight, inLeft, pos - 1);
        ret->right = buildTree(preorder, inorder, preLeft + 1 + pos - inLeft, preRight, pos + 1, inRight);
        return ret;
    }
};