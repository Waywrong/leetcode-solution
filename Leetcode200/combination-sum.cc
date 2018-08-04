//  Combination Sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, comb, res);
        return res;
    }
    
    void dfs(vector<int> &candidates, int target, int cur, 
                vector<int> comb, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i=cur; i<candidates.size(); i++) {
            if (candidates[i] > target) break;
            comb.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, comb, res);
            comb.pop_back();
        }
    }
};