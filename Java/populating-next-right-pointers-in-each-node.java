//  Populating Next Right Pointers in Each Node

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
        connect(root, null);
    }
    
    private void connect(TreeLinkNode p, TreeLinkNode q) {
        if (p == null)
            return;
        else
            p.next = q;
        connect(p.left, p.right);
        if (q != null)
            connect(p.right, q.left);
        else
            connect(p.right, null);
    }
}