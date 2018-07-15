//  Sort List

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// Time O(NlogN), Space O(1)
class Solution {
    public ListNode sortList(ListNode head) {
        int len = getLength(head);
        if (len < 2)
            return head;
        ListNode mid = head, pre = null;
        for (int i=0; i<len/2; i++) {
            pre = mid;
            mid = mid.next;
        }
        ListNode l_head = (mid==head) ? null : head;
        ListNode r_head = mid;
        if (pre != null)
            pre.next = null;
        l_head = sortList(l_head);
        r_head = sortList(r_head);
        ListNode ans = mergeSortedLists(l_head, r_head);
        return ans;
    }
    
    private ListNode mergeSortedLists(ListNode l1, ListNode l2) {
        if (l1==null || l2==null)
            return l1!=null ? l1 : l2;
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
        if (p1 != null)
            p.next = p1;
        if (p2 != null)
            p.next = p2;
        return dummy.next;
    }
    
    private int getLength(ListNode head) {
        int len = 0;
        for (ListNode cur = head; cur != null; cur = cur.next)
            len ++;
        return len;
    }
}