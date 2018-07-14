//  Subsets

// Time O(2^N), Space O(N)
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> subset = new ArrayList<Integer>();
        dfs(nums, 0, subset, ans);
        return ans;
    }
    
    private void dfs(int[] nums, int start, List<Integer> subset, List<List<Integer>> ans) {
        ans.add(new ArrayList(subset));
        for (int i=start; i<nums.length; i++) {
            subset.add(nums[i]);
            dfs(nums, i+1, subset, ans);
            subset.remove(subset.size()-1);
        }
    }
}