
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int adder = 0;
        ListNode dummyHead = new ListNode(0);
        ListNode cur = dummyHead;
        while(true){
            int val = adder;
            if(l1 != null) val += l1.val;
            if(l2 != null) val += l2.val;
            ListNode newNode = new ListNode(val % 10);
            if(val >= 10) adder = 1;
            else adder = 0;
            cur.next = newNode;
            cur = cur.next;
            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
            if(l1 == null && l2 == null) break;
        }
        if(adder == 1) cur.next = new ListNode(1);
        return dummyHead.next;
    }
}

