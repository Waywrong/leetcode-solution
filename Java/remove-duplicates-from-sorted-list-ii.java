//  Remove Duplicates from Sorted List II

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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return null;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode pre = dummy, cur = head;
        while (cur != null) {
            while (cur.next!=null && cur.val==cur.next.val)
                cur = cur.next;
            if (pre.next == cur)
                pre = cur;
            else
                pre.next = cur.next;
            cur = cur.next;
        }
        return dummy.next;
    }
}