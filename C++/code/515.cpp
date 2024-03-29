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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int maximum = INT_MIN;
            for (int i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();
                maximum = max(maximum, top->val);
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            ans.push_back(maximum);
        }
        return ans;
    }
};