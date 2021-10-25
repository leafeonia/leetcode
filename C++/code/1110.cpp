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
    vector<TreeNode*> ans;
    unordered_set<int> todel;
    
    TreeNode* dfs(TreeNode* root, bool isRoot) {
        if (!root) return nullptr; 
        if (todel.find(root->val) != todel.end()) {
            dfs(root->left, true);
            dfs(root->right, true);
            return nullptr;
        } else {
            root->left = dfs(root->left, false);
            root->right = dfs(root->right, false);
            if (isRoot) ans.push_back(root);
            return root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int num: to_delete) todel.insert(num);
        dfs(root, true);
        return ans;
    }
};