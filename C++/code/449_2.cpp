/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root, string& key) {
        if (!root) return;
        key += to_string(root->val) + "/";
        dfs(root->left, key);
        dfs(root->right, key);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string key;
        dfs(root, key);
        key.pop_back();
        return key;
    }

    TreeNode* build(vector<int>& v, int& idx, int mini, int maxi) {
        if (idx == v.size()) return nullptr;
        int val = v[idx];
        if (val < mini || val > maxi) return nullptr;
        idx++;
        TreeNode* node = new TreeNode(val);
        node->left = build(v, idx, mini, val);
        node->right = build(v, idx, val, maxi);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<int> v;
        istringstream ss(data);
        string temp;
        while (getline(ss, temp, '/')) {
            v.push_back(stoi(temp));
        }
        int idx = 0;
        return build(v, idx, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;