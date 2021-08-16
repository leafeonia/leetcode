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
    int record = 0;
    int preVal = INT_MIN;
    int cnt = 0;
    
    void inOrder(TreeNode* root) {
        if (!root) return;
        inOrder(root->left);
        int val = root->val;
        if (val != preVal) {
            preVal = val;
            cnt = 1;
        } else cnt++;
        if (cnt > record) {
            record = cnt;
            ans.clear();
            ans.push_back(val);
        } else if (cnt == record) {
            ans.push_back(val);
        }
        inOrder(root->right);
        
    }
    
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};