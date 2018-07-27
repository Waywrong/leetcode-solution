//  Merge K Sorted Lists

// Time O(NlogK), Space O(N)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<ListNode> t = new ArrayList<ListNode>();
        for (ListNode x : lists)
            t.add(x);
        if (t.size() <= 0)
            return null;
        while (t.size() > 1) {
            int size = t.size();
            for (int i=0; i<size/2; i++) {
                ListNode node = mergeLists(t.get(0), t.get(1));
                t.remove(0); t.remove(0);
                t.add(node);
            }
        }
        return t.get(0);
    }
    
    private ListNode mergeLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p1 = l1, p2 = l2, p = dummy;
        while (p1!=null && p2!=null) {
            if (p1.val < p2.val) {
                p.next = new ListNode(p1.val);
                p1 = p1.next;
            }
            else {
                p.next = new ListNode(p2.val);
                p2 = p2.next;
            }
            p = p.next;
        }
        while (p1 != null) {
            p.next = new ListNode(p1.val);
            p1 = p1.next;
            p = p.next;
        }
        while (p2 != null) {
            p.next = new ListNode(p2.val);
            p2 = p2.next;
            p = p.next;
        }
        return dummy.next;
    }
}
