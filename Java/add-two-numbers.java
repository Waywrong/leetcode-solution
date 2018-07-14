//  Add Two Numbers

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// Time O(M+N), Space O(1)
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy, p1 = l1, p2 = l2;
        int k = 0;
        while (p1!=null || p2!=null) {
            int sum = (p1!=null ? p1.val : 0) + (p2!=null ? p2.val : 0) + k;
            p.next = new ListNode(sum % 10);
            p = p.next;
            p1 = (p1!=null) ? p1.next : null;
            p2 = (p2!=null) ? p2.next : null;
            k = sum / 10;
        }
        if (k == 1)
            p.next = new ListNode(k);
        return dummy.next;
    }
}