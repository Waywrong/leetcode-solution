//  Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

// Time O(M+N), Space O(1)
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pA = headA, pB = headB;
        while (pA!=null || pB!=null) {
            if (pA == pB)   return pA;
            pA = (pA!=null) ? pA.next : headB;
            pB = (pB!=null) ? pB.next : headA;
        }
        return pA;
    }
}