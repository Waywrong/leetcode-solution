//  Linked List Cycle

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
    public boolean hasCycle(ListNode head) {
        if (head == null)
            return false;
        ListNode chaser = head, runner = head;
        while (runner.next!=null && runner.next.next!=null) {
            chaser = chaser.next;
            runner = runner.next.next;
            if (chaser == runner)
                return true;
        }
        return false;
    }
}