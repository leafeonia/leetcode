/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* cur = head;
        while (cur) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        cur = head;
        while (cur) {
            cur->next->random = cur->random ? cur->random->next : nullptr; //
            cur = cur->next->next;
        }
        
        cur = head;
        Node* ret = head->next;
        while (cur) {
            Node* nextOrigin = cur->next->next;
            if (nextOrigin) {
                cur->next->next = nextOrigin->next;
            }
            cur->next = nextOrigin;
            cur = nextOrigin;
        }
        
        return ret;
    }
};