/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        } 
        Node* lastNode = head;
        while (lastNode->next != head) {
            if (insertVal <= lastNode->next->val &&
               (lastNode->val <= insertVal || lastNode->val > lastNode->next->val)) break;
            if (lastNode->val > lastNode->next->val && insertVal >= lastNode->val) break;
            lastNode = lastNode->next;
        }
        Node* node = new Node(insertVal);
        node->next = lastNode->next;
        lastNode->next = node;
        return head;
    }
};


// 1 2 3 4 5