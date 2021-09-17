/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = 0;
    
    int solve(Node* root) {
        if (!root || root->children.empty()) return 0;
        vector<int> v;
        int h1 = 0, h2 = 0;
        for (auto child: root->children) {
            int h = solve(child) + 1;
            if (h > h1) {
                h2 = h1;
                h1 = h;
            } else if (h > h2) {
                h2 = h;
            }
        }
        ans = max(ans, h1 + h2);
        return h1;
        
    }
    
    int diameter(Node* root) {
        solve(root);
        return ans;
    }
};