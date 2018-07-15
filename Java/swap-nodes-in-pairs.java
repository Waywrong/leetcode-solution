//  Swap Nodes in Pairs

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
    public ListNode swapPairs(ListNode head) {
        if (head==null || head.next==null)
            return head;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy, nxt = null, t = null;
        while (pre.next!=null && pre.next.next!=null) {
            nxt = pre.next.next.next;
            t = pre.next;
            pre.next = t.next;
            pre.next.next = t;
            t.next = nxt;
            pre = t;
        }
        return dummy.next;
    }
}