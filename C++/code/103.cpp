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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> v;
            for (int i = 0; i < sz; i++) {
                auto front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            if (ans.size() % 2 == 1) reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};