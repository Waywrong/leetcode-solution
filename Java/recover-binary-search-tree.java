//  Recover Binary Search Tree

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
    public void recoverTree(TreeNode root) {
        if (root==null)
            return;
        if (root.left==null && root.right==null)
            return;
        TreeNode r1 = null, r2 = null;
        TreeNode p = root, pre = null, f = null;
        while (p != null) {
            f = p.left;
            if (f != null) {
                while (f.right!=null && f.right!=p)
                    f = f.right;
                if (f.right == null) {
                    f.right = p;
                    p = p.left;
                    continue;
                }
                else
                    f.right = null;
            }
            if (pre!=null && p.val<pre.val) {
                r1 = pre;
                break;
            }
            pre = p;
            p = p.right;
        }
        p = root; pre = null; f = null;
        while (p != null) {
            f = p.right;
            if (f != null) {
                while (f.left!=null && f.left!=p)
                    f = f.left;
                if (f.left == null) {
                    f.left = p;
                    p = p.right;
                    continue;
                }
                else
                    f.left = null;
            }
            if (pre!=null && p.val>pre.val) {
                r2 = pre;
                break;
            }
            pre = p;
            p = p.left;
        }
        int temp = r1.val; r1.val = r2.val; r2.val = temp; 
    }
}