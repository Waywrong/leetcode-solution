//  Subsets II

// Time O(2^N), Space O(N)
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> subset = new ArrayList<Integer>();
        Arrays.sort(nums);
        dfs(nums, 0, subset, ans);
        return ans;
    }
    
    private void dfs(int[] nums, int start, List<Integer> subset, List<List<Integer>> ans) {
        if (ans.indexOf(subset) == -1)
            ans.add(new ArrayList(subset));
        for (int i=start; i<nums.length; i++) {
            subset.add(nums[i]);
            dfs(nums, i+1, subset, ans);
            subset.remove(subset.size()-1);
        }
    }
}