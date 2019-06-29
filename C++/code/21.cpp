class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* ret;
        if(!cur1 && !cur2) return NULL;
        if(cur1 && (!cur2 || cur1->val <= cur2->val)){
            ret = new ListNode(cur1->val);
            cur1 = cur1->next;
        }
        else{
            ret = new ListNode(cur2->val);
            cur2 = cur2->next;
        }
        ListNode* cur = ret;
        while(cur1 || cur2){
            if(cur1 && (!cur2 || cur1->val <= cur2->val)){
                ListNode *temp = new ListNode(cur1->val);
                cur->next = temp;
                cur = temp;
                cur1 = cur1->next;
            }
            else{
                ListNode *temp = new ListNode(cur2->val);
                cur->next = temp;
                cur = temp;
                cur2 = cur2->next;
            }
        }
        return ret;
    }
};