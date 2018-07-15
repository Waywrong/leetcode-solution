//  Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Time O(N), Space O(1)
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null)
            return null;
        int len = getLength(head);
        ListNode cur = head, pre = null;
        for (int i=0; i<len/2; i++) {
            pre = cur;
            cur = cur.next;
        }
        ListNode l_head = (cur==head) ? null : head;
        ListNode r_head = cur.next;
        if (pre != null)
            pre.next = null;
        TreeNode root = new TreeNode(cur.val);
        root.left = sortedListToBST(l_head);
        root.right = sortedListToBST(r_head);
        return root;
    }
    
    private int getLength(ListNode head) {
        int len = 0;
        for (ListNode cur=head; cur!=null; cur=cur.next)
            len ++;
        return len;
    }
}