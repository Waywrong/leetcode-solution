//  Reorder List

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// Time O(N^2), Space O(1)
class Solution {
    public void reorderList(ListNode head) {
        if (head==null || head.next==null)
            return;
        ListNode p = head.next, pre = head;
        while (p != null) {
            p = reverseList(p);
            pre.next = p;
            pre = p;
            p = p.next;
        }
    }
    
    private ListNode reverseList(ListNode head) {
        if (head==null || head.next==null)
            return head;
        ListNode pre = null, cur = head, nxt = null;
        while (cur != null) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
}