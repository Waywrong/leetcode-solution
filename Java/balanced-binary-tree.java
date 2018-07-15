//  Balanced Binary Tree

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
    public boolean isBalanced(TreeNode root) {
        return getHeight(root) >= 0;
    }
    
    private int getHeight(TreeNode root) {
        if (root == null)
            return 0;
        int l_height = getHeight(root.left);
        int r_height = getHeight(root.right);
        if (l_height==-1 || r_height==-1 || Math.abs(l_height-r_height)>1)
            return -1;
        return (l_height > r_height) ? (l_height + 1) : (r_height + 1);
    }
}