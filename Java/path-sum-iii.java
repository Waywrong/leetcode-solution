//  Path Sum III

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Time O(N^2), Space O(1)
class Solution {
    public int pathSum(TreeNode root, int sum) {
        if (root == null)
            return 0;
        return sumUp(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
    }
    
    private int sumUp(TreeNode root, int sum) {
        int res = 0;
        if (root == null)
            return 0;
        if (root.val == sum)
            res ++;
        res += sumUp(root.left, sum - root.val);
        res += sumUp(root.right, sum - root.val);
        return res;
    }
}