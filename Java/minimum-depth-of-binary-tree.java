//  Minimum Depth of Binary Tree

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
    public int minDepth(TreeNode root) {
        if (root == null)   return 0;
        int l_h = minDepth(root.left);
        int r_h = minDepth(root.right);
        if (l_h == 0 || r_h == 0)
            return l_h==0 ? r_h + 1 : l_h + 1;
        else
            return Math.min(l_h, r_h) + 1;
    }
}