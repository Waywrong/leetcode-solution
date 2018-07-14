//  Construct Binary Tree from Inorder and Postorder Traversal

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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length!=postorder.length || inorder.length==0)
            return null;
        int size = inorder.length, root_val = postorder[size-1];
        int left_size = 0, right_size = 0;
        for (int i=0; i<size && inorder[i]!=root_val; i++)
            left_size ++;
        right_size = size - 1 - left_size;
        int[] left_inorder = new int[left_size];
        int[] left_postorder = new int[left_size];
        int[] right_inorder = new int[right_size];
        int[] right_postorder = new int[right_size];
        for (int i=0; i<left_size; i++) {
            left_inorder[i] = inorder[i];
            left_postorder[i] = postorder[i];
        }
        for (int i=0; i<right_size; i++) {
            right_inorder[i] = inorder[i+left_size+1];
            right_postorder[i] = postorder[i+left_size];
        }
        TreeNode root = new TreeNode(root_val);
        root.left = buildTree(left_inorder, left_postorder);
        root.right = buildTree(right_inorder, right_postorder);
        return root;
    }
}