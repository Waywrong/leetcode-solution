//  Sum Root to Leaf Numbers

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
    private int sum = 0;
    
    public int sumNumbers(TreeNode root) {
        if (root == null)
            return 0;
        dfs(root, 0);
        return sum;
    }
    
    private void dfs(TreeNode root, int pre_sum) {
        if (root == null)
            return;
        pre_sum = pre_sum * 10 + root.val;
        if (root.left==null && root.right==null)
            sum += pre_sum;
        dfs(root.left, pre_sum);
        dfs(root.right, pre_sum);
        pre_sum /= 10;
    }
}

// Time O(N), Space O(N)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int sumNumbers(TreeNode root) {
        int ans = 0, sum = 0;
        if (root == null)
            return ans;
        Stack<TreeNode> s = new Stack<TreeNode>();
        TreeNode p = root, last = null;
        while (p != null) {
            s.push(p);
            sum = sum * 10 + p.val;
            p = p.left;
        }
        while (!s.empty()) {
            p = s.peek();
            if (p.right==null || p.right==last) {
                if (p.left==null && p.right==null)
                    ans += sum;
                sum /= 10;
                last = p;
                s.pop();
            }
            else {
                p = p.right;
                while (p != null) {
                    s.push(p);
                    sum = sum * 10 + p.val;
                    p = p.left;
                }
            }
        }
        return ans;
    }
}