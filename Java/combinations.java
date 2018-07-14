//  Combinations

// Time O(N!), Space O(N)
class Solution {
    private List<List<Integer>> ans = new ArrayList<List<Integer>>();
    private List<Integer> comb = new ArrayList<Integer>();
    
    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }
    
    private void dfs(int n, int k, int start) {
        if (comb.size() == k) {
            ans.add(new ArrayList(comb));
            return;
        }
        for (int i=start; i<=n; i++) {
            comb.add(i);
            dfs(n, k, i+1);
            comb.remove(comb.size()-1);
        }
    }
}