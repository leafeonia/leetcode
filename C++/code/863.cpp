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
    int dfs(TreeNode* root) { // return the distance between caller and target
        if (!root) return -1;
        if (root == target) {
            add(root, k);
            return 1;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left != -1) {
            if (left == k) ans.push_back(root->val);
            add(root->right, k - left - 1);
            return left + 1;
        }
        if (right != -1) {
            if (right == k) ans.push_back(root->val);
            add(root->left, k - right - 1);
            return right + 1;
        }
        return -1;
    }
    
    void add(TreeNode* root, int dist) {
        if (!root || dist < 0) return;
        if (dist == 0) {
            ans.push_back(root->val);
            return;
        }
        add(root->left, dist - 1);
        add(root->right, dist - 1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        this->target = target;
        dfs(root);
        return ans;
    }
    
    int k;
    TreeNode* target;
    vector<int> ans;
    
};