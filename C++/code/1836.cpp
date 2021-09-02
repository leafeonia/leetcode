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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* sentinel = new ListNode();
        sentinel->next = head;
        unordered_map<int, int> mp;
        ListNode* cur = head;
        while (cur) {
            mp[cur->val]++;
            cur = cur->next;
        }
        ListNode* prev = sentinel;
        cur = head;
        while (cur) {
            if (mp[cur->val] < 2) {
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        return sentinel->next;
    }
};