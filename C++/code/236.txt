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
    TreeNode* ans;
public:
    int search(TreeNode* cur, TreeNode* p, TreeNode* q){
        if(!cur) return 0;
        int ret = 0;
        if(cur == p || cur == q) ret = 1;
        int left = search(cur->left,p, q);
        int right = search(cur->right, p, q);
        if(left + right + (cur == p || cur == q) == 2){
            ans = cur;
            return 3;
        }
        return ret+left+right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p, q);
        return ans;
    }
};