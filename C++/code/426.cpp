/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void inorder(Node* root) {
        if (!root) return;
        if (!root->left && !first) first = root;
        inorder(root->left);
        if (prev) {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        inorder(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        first = prev = nullptr;
        inorder(root);
        if (first) {
            first->left = prev;
            prev->right = first;
        }
        return first;
    }
    
    Node* first;
    Node* prev;
};

//      6
//    4   8
//  2  5 7  9
// 1 3       11
//          10