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
        if(node->right){
            Node* ans = node->right;
            while(ans->left) ans = ans->left;
            return ans;
        }
        int val = node->val;
        Node* p = node->parent;
        while(p && p->val < val) p = p->parent;
        if(!p) return NULL;
        return p;
    }
};