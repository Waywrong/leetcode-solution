//  Populating Next Right Pointers in Each Node II

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */

// Time O(N), Space O(1)
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;
        TreeLinkNode dummy = new TreeLinkNode(-1);
        for (TreeLinkNode cur = root, pre = dummy; cur != null; cur = cur.next) {
            if (cur.left != null) {
                pre.next = cur.left;
                pre = cur.left;
            }
            if (cur.right != null) {
                pre.next = cur.right;
                pre = cur.right;
            }
        }
        connect(dummy.next);
    }
}

/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */

// Time O(N), Space O(1)
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null)
            return;
        TreeLinkNode dummy = new TreeLinkNode(-1);
        dummy.next = root;
        while (dummy.next != null) {
            TreeLinkNode cur_dummy = new TreeLinkNode(-1);
            for (TreeLinkNode cur = dummy.next, pre = cur_dummy; cur != null; cur = cur.next) {
                if (cur.left != null) {
                    pre.next = cur.left;
                    pre = cur.left;
                }
                if (cur.right != null) {
                    pre.next = cur.right;
                    pre = cur.right;
                }
            }
            dummy = cur_dummy;
        }
    }
}