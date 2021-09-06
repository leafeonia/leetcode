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
    void traverse(TreeNode* root, int row, int col) {
        if (!root) return;
        mp[col][row].insert(root->val);
        traverse(root->left, row + 1, col - 1);
        traverse(root->right, row + 1, col + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        vector<vector<int>> ans;
        for (auto ele: mp) {
            vector<int> v;
            for (auto mp2: ele.second) {
                v.insert(v.end(), mp2.second.begin(), mp2.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
    
    map<int, map<int, multiset<int>>> mp;
};