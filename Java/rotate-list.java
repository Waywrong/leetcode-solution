//  Rotate List

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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return null;
        int len = getLength(head);
        k %= len;
        if (k == 0)
            return head;
        ListNode p1 = head, p2 = head;
        for (int i=0; i<k; i++)
            p2 = p2.next;
        while (p2.next != null) {
            p1 = p1.next;
            p2 = p2.next;
        }
        p2.next = head;
        head = p1.next;
        p1.next = null;
        return head;
    }
    
    private int getLength(ListNode head) {
        int len = 0;
        for (ListNode p = head; p != null; p = p.next)
            len ++;
        return len;
    }
}