//   Maximum Depth of Bianry Tree

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
    public int maxDepth(TreeNode root) {
        if (root == null)   return 0;
        int l_h = maxDepth(root.left);
        int r_h = maxDepth(root.right);
        return (l_h > r_h) ? (l_h + 1) : (r_h + 1);
    }
}