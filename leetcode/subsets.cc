//  Subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
    
    void dfs(vector<int> &nums, int cur, vector<int> &subset, vector<vector<int>> &res) {
        res.push_back(subset);
        if (cur == nums.size()) return;
        for (int i=cur; i<nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, i+1, subset, res);
            subset.pop_back();
        }
    }
};