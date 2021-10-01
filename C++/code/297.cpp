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
    void dfs(TreeNode* root) {
        if (!root) {
            s += "*,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left);
        dfs(root->right);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);
        s.pop_back();
        return s;
    }

    TreeNode* decode(vector<int>& v, int& idx) {
        if (v[idx] == 1001) {
            idx++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(v[idx++]);
        node->left = decode(v, idx);
        node->right = decode(v, idx);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        istringstream ss(data);
        string buffer;
        while (getline(ss, buffer, ',')) {
            if (buffer == "*") v.push_back(1001);
            else v.push_back(stoi(buffer));
        }
        int idx = 0;
        return decode(v, idx);
    }
    
    string s;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));