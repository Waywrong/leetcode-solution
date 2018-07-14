//  Reverse Linked List

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
    public ListNode reverseList(ListNode head) {
        if (head==null || head.next==null)
            return head;
        ListNode pre = null, cur = head, nxt = null;
        while (cur != null) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
}

// Time O(N), Space O(1)
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head==null || head.next==null)
            return head;
        ListNode node = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return node;
    }
}