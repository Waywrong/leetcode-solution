//  Symmetric Tree

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
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSameTree(root.left, root.right);
    }
    
    private boolean isSameTree(TreeNode p, TreeNode q) {
        if (p==null && q==null)
            return true;
        if (p==null || q==null || p.val!=q.val)
            return false;
        return isSameTree(p.left, q.right) && isSameTree(p.right, q.left);
    }
}

// Time O(N), Space O(N)
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        Queue<TreeNode> q1 = new LinkedList<TreeNode>();
        Queue<TreeNode> q2 = new LinkedList<TreeNode>();
        q1.offer(root); q2.offer(root);
        while (q1.size()!=0 && q2.size()!=0) {
            TreeNode p1 = q1.peek(); q1.poll();
            TreeNode p2 = q2.peek(); q2.poll();
            if ((p1==null && p2==null) || (p1!=null && p2!=null && p1.val==p2.val)) {
                if (p1 != null) {
                    q1.offer(p1.left);
                    q1.offer(p1.right);
                }
                if (p2 != null) {
                    q2.offer(p2.right);
                    q2.offer(p2.left);
                }
            }
            else
                return false;
        }
        return true;
    }
}