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
    TreeNode* build(string& s, int& idx) {
        string num;
        while (idx < s.length() && s[idx] != '(' && s[idx] != ')') {
            num += s[idx++];
        }
        TreeNode* node = new TreeNode(stoi(num));
        if (idx < s.length() && s[idx] == '(') {
            idx++;
            node->left = build(s, idx);
            idx++;
        } else {
            node->left = nullptr;
        }
        if (idx < s.length() && s[idx] == '(') {
            idx++;
            node->right = build(s, idx);
            idx++;
        } else {
            node->right = nullptr;
        }
        return node;
    }
    
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        int idx = 0;
        return build(s, idx);
    }
};