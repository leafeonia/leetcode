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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> a, b;
        vector<int> ans;
        while (root1 || root2 || !a.empty() || !b.empty()) {
            while (root1) {
                a.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                b.push(root2);
                root2 = root2->left;
            }
            if (b.empty() || (!a.empty() && a.top()->val < b.top()->val)) {
                root1 = a.top();
                ans.push_back(root1->val);
                a.pop();
                root1 = root1->right;
            } else {
                root2 = b.top();
                ans.push_back(root2->val);
                b.pop();
                root2 = root2->right;
            }
        }
        return ans;
        
    }
};