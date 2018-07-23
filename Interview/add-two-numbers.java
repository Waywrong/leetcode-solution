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
        int carry = 0;
        while (p1!=null || p2!=null) {
            int sum = (p1!=null ? p1.val : 0) + (p2!=null ? p2.val : 0) + carry;
            p.next = new ListNode(sum % 10);
            carry = sum / 10;
            p1 = (p1!=null ? p1.next : null);
            p2 = (p2!=null ? p2.next : null);
            p = p.next;
        }
        if (carry != 0) 
            p.next = new ListNode(carry);
        return dummy.next;
    }
}