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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int cnt1 = 0, cnt2 = 0;
        Node* pp = p;
        Node* qq = q;
        while (pp) {
            pp = pp->parent;
            cnt1++;
        }
        while (qq) {
            qq = qq->parent;
            cnt2++;
        }
        Node* far;
        Node* near;
        if (cnt1 < cnt2) {
            far = q;
            near = p;
        } else {
            far = p;
            near = q;
        }
        for (int i = 0; i < abs(cnt1 - cnt2); i++) {
            far = far->parent;
        }
        while (far != near) {
            far = far->parent;
            near = near->parent;
        }
        return far;
    }
};