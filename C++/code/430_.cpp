/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* root, Node* prev) {
        if (!root) return prev;
        prev->next = root;
        root->prev = prev;
        
        Node* next = root->next;
        Node* tail = solve(root->child, root);
        root->child = nullptr;
        
        return solve(next, tail);
    }
    
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        Node* sentinel = new Node();
        sentinel->next = head;
        solve(head, sentinel);
        head->prev = nullptr;
        return head;
    }
};