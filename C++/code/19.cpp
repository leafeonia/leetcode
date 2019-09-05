/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int le = 0;
        while(cur){
            cur = cur->next;
            le++;
        }
        if(le == n){
            ListNode* next = head->next;
            head->next = NULL;
            return next;
        }
        le = le - n;
        cur = head;
        for(int i = 0;i < le - 1;i++){
            cur = cur->next;
        }
        ListNode* del = cur->next;
        cur->next = del->next;
        del->next = NULL;
        return head;
    }
};//
// Created by maoym on 2019/9/5.
//

