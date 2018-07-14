//  Reverse Linked List II

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode p = dummy, cur = head, pre = null, nxt = null;
        int cnt = 1;
        while (cnt++ < m) {
            p = cur;
            cur = cur.next;
        }
        pre = p;
        while (cnt ++ <= n+1) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        p.next.next = cur;
        p.next = pre;
        return dummy.next;
    }
}