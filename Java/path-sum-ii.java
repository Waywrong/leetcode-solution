//  Path Sum II

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(root, sum, path, ans);
        return ans;
    }
    
    private void dfs(TreeNode root, int sum, List<Integer> path, List<List<Integer>> ans) {
        if (root == null)
            return;
        path.add(root.val);
        sum -= root.val;
        if (root.left==null && root.right==null && sum==0)
            ans.add(new ArrayList(path));
        dfs(root.left, sum, path, ans);
        dfs(root.right, sum, path, ans);
        path.remove(path.size()-1);
    }
}