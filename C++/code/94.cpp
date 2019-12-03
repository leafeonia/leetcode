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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) {
            vector<int> empty;
            return empty;
        }
        vector<int> ret;
        for (auto ele: inorderTraversal(root->left)){
            ret.push_back(ele);
        }
        ret.push_back(root->val);
        for (auto ele: inorderTraversal(root->right)){
            ret.push_back(ele);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        map<TreeNode*, bool> met;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(!node) continue;
            if(!met[node]){
                st.push(node->right);
                st.push(node);
                st.push(node->left);
                met[node] = true;
            }
            else ret.push_back(node->val);
        }
        return ret;
    }
};