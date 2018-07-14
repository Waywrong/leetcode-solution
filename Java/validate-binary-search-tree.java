//  Validate Binary Search Tree

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
    public boolean isValidBST(TreeNode root) {
        if (root == null)
            return true;
        if (root.left != null) {
            TreeNode p = root.left;
            while (p.right != null)
                p = p.right;
            if (p.val >= root.val)
                return false;
        }
        if (root.right != null) {
            TreeNode p = root.right;
            while (p.left != null)
                p = p.left;
            if (p.val <= root.val)
                return false;
        }
        return isValidBST(root.left) && isValidBST(root.right);
    }
}