/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (mp.find(node) != mp.end()) return mp[node];
        Node* newnode = new Node(node->val);
        mp[node] = newnode;
        for (auto next: node->neighbors) {
            newnode->neighbors.push_back(cloneGraph(next));
        }
        return newnode;
    }
    
    unordered_map<Node*, Node*> mp;
};