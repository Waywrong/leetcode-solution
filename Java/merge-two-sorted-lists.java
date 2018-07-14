//  Merge Two Sorted Lists

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy, p1 = l1, p2 = l2;
        while (p1!=null && p2!=null) {
            if (p1.val < p2.val) {
                p.next = p1;
                p1 = p1.next;
            }
            else {
                p.next = p2;
                p2 = p2.next;
            }
            p = p.next;
        }
        p.next = (p1 != null) ? p1 : p2;
        return dummy.next;
    }
}