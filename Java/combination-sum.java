//  Combination Sum

// Time O(N!), Space O(1)
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        dfs(candidates, target, 0, comb, ans);
        return ans;
    }
    
    private void dfs(int[] candidates, int target, int start, List<Integer> comb, List<List<Integer>> ans) {
        if (target < 0)
            return;
        if (target == 0)
            ans.add(new ArrayList(comb));
        for (int i=start; i<candidates.length; i++) {
            comb.add(candidates[i]);
            dfs(candidates, target-candidates[i], i, comb, ans);
            comb.remove(comb.size()-1);
        }
    }
}