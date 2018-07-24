//  Convert Sorted Array to Binary Search Tree

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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length <= 0)   return null;
        return sortedArrayToBST(nums, 0, nums.length-1);
    }
    
    private TreeNode sortedArrayToBST(int[] nums, int left, int right) {
        if (left > right)   return null;
        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = sortedArrayToBST(nums, left, mid-1);
        root.right = sortedArrayToBST(nums, mid+1, right);
        return root;
    }
}