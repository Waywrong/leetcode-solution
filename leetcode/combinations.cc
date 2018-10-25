//  Combinations

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(n, k, 1, comb, res);
        return res;
    }
    
    void dfs(int n, int k, int cur, vector<int> &comb, vector<vector<int>> &res) {
        if (k == 0) {
            res.push_back(comb);
            return;
        }
        for (int i=cur; i<=n; i++) {
            comb.push_back(i);
            dfs(n, k-1, i+1, comb, res);
            comb.pop_back();
        }
    }
};