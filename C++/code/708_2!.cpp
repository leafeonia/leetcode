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
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        Node* last = head;
        while (last->next != head) {
            Node* next = last->next;
            int a = last->val, b = insertVal, c = next->val;
            if (a <= b && b <= c) break;
            if (b <= c && a > c) break;
            if (b >= a && a > c) break;
            last = last->next;
        }
        Node* node = new Node(insertVal);
        node->next = last->next;
        last->next = node;
        return head;
    }
};