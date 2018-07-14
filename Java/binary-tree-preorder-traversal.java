//  Binary Tree Preorder Traversal

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if (root == null)
            return ans;
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode p = root;
        while (p != null || !s.empty()) {
            if (p != null) {
                ans.add(p.val);
                s.push(p);
                p = p.left;
            }
            else {
                p = s.pop();
                p = p.right;
            }
        }
        return ans;
    }
}

// Time O(N), Space O(1)
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if (root == null)
            return ans;
        TreeNode p = root, free = null;
        while (p != null) {
            free = p.left;
            if (free != null) {
                while (free.right!=null && free.right!=p)
                    free = free.right;
                if (free.right == null) {
                    free.right = p;
                    ans.add(p.val);
                    p = p.left;
                    continue;
                }
                else
                    free.right = null;
            }
            else
                ans.add(p.val);
            p = p.right;
        }
        return ans;
    }
}