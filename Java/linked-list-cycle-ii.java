//  Linked List Cycle II

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

// Time O(N), Space O(1)
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return null;
        ListNode runner = head, chaser = head;
        while (runner.next!=null && runner.next.next!=null) {
            chaser = chaser.next;
            runner = runner.next.next;
            if (chaser == runner) {
                while (head != chaser) {
                    head = head.next;
                    chaser = chaser.next;
                }
                return head;
            }
        }
        return null;
    }
}