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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            v.push_back(front);
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
    
    int insert(int val) {
        int n = v.size();
        TreeNode* node = new TreeNode(val);
        v.push_back(node);
        if (n % 2 == 1) v[(n - 1) / 2]->left = v[n];
        else v[(n - 1) / 2]->right = v[n];
        return v[(n - 1) / 2]->val;
    }
    
    TreeNode* get_root() {
        return v[0];
    }
    
    vector<TreeNode*> v;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */