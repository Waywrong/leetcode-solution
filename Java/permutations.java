//  Permutations

// Time O(N!), Space O(N)
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        dfs(nums, 0, ans);
        return ans;
    }
    
    private void dfs(int[] nums, int start, List<List<Integer>> ans) {
        if (start >= nums.length) {
            List<Integer> comb = new ArrayList<Integer>();
            for (int i=0; i<nums.length; i++)
                comb.add(nums[i]);
            ans.add(comb);
        }
        for (int i=start; i<nums.length; i++) {
            int temp = nums[i]; nums[i] = nums[start]; nums[start] = temp;
            dfs(nums, start+1, ans);
            temp = nums[i]; nums[i] = nums[start]; nums[start] = temp;
        }
    }
}