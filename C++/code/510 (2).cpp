/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            Node* ans = node->right;
            while (ans->left) ans = ans->left;
            return ans;
        }
        while (node->parent && node->parent->right == node) node = node->parent;
        return node->parent;
    }
};