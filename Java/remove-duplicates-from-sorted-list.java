//  Remove Duplicates from Sorted List

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
        if (head==null)
            return null;
        ListNode pre = head, cur = head.next;
        while (cur != null) {
            if (cur.val != pre.val) {
                pre.next = cur;
                pre = cur;
            }
            cur = cur.next;
        }
        pre.next = cur;
        return head;
    }
}