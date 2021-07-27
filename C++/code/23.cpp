/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        int n = lists.size();
        ListNode* sentinel = new ListNode();
        ListNode* cur = sentinel;
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                pq.push(lists[i]);
                lists[i] = lists[i]->next; 
            }
        }
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next) {
                pq.push(top->next);
            }
        }
        ListNode* ret = sentinel->next;
        delete sentinel;
        return ret;
    }
};