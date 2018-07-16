//  Reverse Nodes in K-groups

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// Time O(N), Space O(1)
class Solution {
    private ListNode pre = null;
    private ListNode nxt = null;
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if (k < 2)
            return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        this.pre = dummy;
        ListNode temp = null, p = null;
        int len = getLength(this.pre.next);
        while (len >= k) {
            p = this.pre;
            temp = p.next;
            reverseList(p.next, k);
            p.next = this.pre;
            temp.next = this.nxt;
            this.pre = temp;
            len = getLength(this.pre.next);
        }
        return dummy.next;
    }
    
    private int getLength(ListNode head) {
        int len = 0;
        for (ListNode cur = head; cur != null; cur = cur.next)
            len ++;
        return len;
    }
    
    private void reverseList(ListNode head, int k) {
        if (head==null || head.next==null)
            return;
        ListNode cur = head;
        int step = 0;
        while (step++ < k) {
            this.nxt = cur.next;
            cur.next = this.pre;
            this.pre = cur;
            cur = this.nxt;
        }
    }
}