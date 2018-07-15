//  Remove Nth Node From End of List

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null)
            return null;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy, cur = head;
        for (int i=0; i<n; i++)
            cur = cur.next;
        for (; cur!=null; cur=cur.next)
            pre = pre.next;
        pre.next = pre.next.next;
        return dummy.next;
    }
}