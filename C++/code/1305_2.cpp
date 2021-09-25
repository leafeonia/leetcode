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
    void leftMost(TreeNode* root, stack<TreeNode*> &st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> a, b;
        leftMost(root1, a);
        leftMost(root2, b);
        while (!a.empty() || !b.empty()) {
            if (b.empty() || (!a.empty() && a.top()->val < b.top()->val)) {
                TreeNode* top = a.top();
                ans.push_back(top->val);
                a.pop();
                leftMost(top->right, a);
            } else {
                TreeNode* top = b.top();
                ans.push_back(top->val);
                b.pop();
                leftMost(top->right, b);
            }
        }
        return ans;
    }
};