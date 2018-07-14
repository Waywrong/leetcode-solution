//  Construt Binary Tree from Preorder and Inorder Traversal

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// Time O(N), Space O(N)
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int pre_size = preorder.length, in_size = inorder.length;
        if (pre_size != in_size || pre_size == 0)
            return null;
        int size = pre_size;
        int root_val = preorder[0];
        int left_size = 0, right_size;
        for (int i=0; i<size && inorder[i]!=root_val; i++)
            left_size ++;
        right_size = size - left_size - 1;
        int[] left_pre_arr = new int[left_size];
        int[] left_in_arr = new int[left_size];
        int[] right_pre_arr = new int[right_size];
        int[] right_in_arr = new int[right_size];
        for (int i=0; i<left_size; i++) {
            left_pre_arr[i] = preorder[i+1];
            left_in_arr[i] = inorder[i];
        }
        for (int i=0; i<right_size; i++) {
            right_pre_arr[i] = preorder[i+left_size+1];
            right_in_arr[i] = inorder[i+left_size+1];
        }
        TreeNode root = new TreeNode(root_val);
        root.left = buildTree(left_pre_arr, left_in_arr);
        root.right = buildTree(right_pre_arr, right_in_arr);
        return root;
    }
}