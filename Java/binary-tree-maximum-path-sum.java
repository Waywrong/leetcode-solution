//  Binary Tree Maximum Path Sum

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
    private int max_sum = Integer.MIN_VALUE;
    
    public int maxPathSum(TreeNode root) {
        dfs(root);
        return max_sum;
    }
    
    private int dfs(TreeNode root) {
        if (root == null)
            return 0;
        int l_sum = dfs(root.left);
        int r_sum = dfs(root.right);
        int sum = root.val;
        if (l_sum > 0)
            sum += l_sum;
        if (r_sum > 0)
            sum += r_sum;
        max_sum = Math.max(max_sum, sum);
        return Math.max(l_sum, r_sum)>0 ? Math.max(l_sum, r_sum) + root.val : root.val;
    }
}