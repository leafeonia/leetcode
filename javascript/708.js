/**
 * // Definition for a Node.
 * function Node(val,next) {
 *    this.val = val;
 *    this.next = next;
 * };
 */
/**
 * @param {Node} head
 * @param {number} insertVal
 * @return {Node}
 */

var insert = function(head, insertVal) {
    if(head == null) {
        let ret = new Node(insertVal, null);
        ret.next = ret;
        return ret;
    }
    let cur = head.next;
    while(cur.val <= cur.next.val && cur.next !== head) cur = cur.next;
    if(insertVal >= cur.val){ //bigger than any node val
        cur.next = new Node(insertVal, cur.next);
        return head;
    }
    // let biggest = cur;
    while(insertVal > cur.next.val) cur = cur.next;
    cur.next = new Node(insertVal, cur.next);
    return head;
};

// let n1 = new Node(3, null);
// let n2 = new Node(1, n1);
// let n3 = new Node(4, n2);
// n1.next = n3;
// insert(n1, 2);
// let cur = n2;
// console.log(n1.val);
// while(cur !== n1) {
//     console.log(cur.val);
//     cur = cur.next;
// }
// let n1 = insert(null, 1);
// console.log(n1.next.val);
