//  Subsets II

// Time O(2^N), Space O(N)
class Solution {
    private List<List<Integer>> ans = new ArrayList<List<Integer>>();
    private List<Integer> subset = new ArrayList<Integer>();
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        dfs(nums, 0);
        return this.ans;
    }
    
    private void dfs(int[] nums, int start) {
        if (!this.ans.Contains(this.subset)) 
            this.ans.add(this.subset);
        for (int i=start; i<nums.length; i++) {
            this.subset.add(nums[i]);
            dfs(nums, i+1);
            this.subset.remove(this.subset.size()-1);
        }
    }
}