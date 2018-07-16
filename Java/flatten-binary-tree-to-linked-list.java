//  Flatten Binary Tree to Linked List

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
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        if (root.left == null) {
            flatten(root.right);
            return;
        }
        TreeNode temp = root.right;
        flatten(root.left);
        root.right = root.left;
        root.left = null;
        flatten(temp);
        TreeNode p = root;
        while (p.right != null)
            p = p.right;
        p.right = temp;
    }
}

// Time O(N), Space O(N)
class Solution {
    public void flatten(TreeNode root) {
        if (root == null)
            return;
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        while (!s.empty()) {
            TreeNode t = s.peek();
            s.pop();
            if (t.right != null)
                s.push(t.right);
            if (t.left != null)
                s.push(t.left);
            t.left = null;
            if (!s.empty())
                t.right = s.peek();
        }
    }
}