//  Combination Sum II

// Time O(N!), Space O(N)
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> comb = new ArrayList<Integer>();
        Arrays.sort(candidates);
        dfs(candidates, target, 0, comb, ans);
        return ans;
    }
    
    private void dfs(int[] candidates, int target, int start, List<Integer> comb, List<List<Integer>> ans) {
        if (target < 0)
            return;
        if (target == 0)
            ans.add(new ArrayList(comb));
        int prev = -1;
        for (int i=start; i<candidates.length; i++) {
            if (candidates[i] == prev)
                continue;
            prev = candidates[i];
            comb.add(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, comb, ans);
            comb.remove(comb.size()-1);
        }
    }
}