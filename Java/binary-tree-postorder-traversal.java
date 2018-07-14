//  Binary Tree Postorder Traversal

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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if (root == null)
            return ans;
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode p = root, last = null;
        while (p != null) {
            s.push(p);
            p = p.left;
        }
        while (!s.empty()) {
            p = s.peek();
            if (p.right==null || p.right==last) {
                ans.add(p.val);
                last = p;
                s.pop();
            }
            else {
                p = p.right;
                while (p != null) {
                    s.push(p);
                    p = p.left;
                }
            }
        }
        return ans;
    }
}