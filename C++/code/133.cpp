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
    unordered_map<int, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        Node* newNode = new Node(node->val);
        mp[node->val] = newNode;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto neighbor: front->neighbors) {
                if (mp.find(neighbor->val) == mp.end()) {
                    Node* newNode = new Node(neighbor->val);
                    mp[neighbor->val] = newNode;
                    q.push(neighbor);
                }
                mp[front->val]->neighbors.push_back(mp[neighbor->val]);
            }
        }
        return mp[node->val];
        
    }
};