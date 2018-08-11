//  Path Sum II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
//  Solution 1
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int cur_sum = 0;
        dfs(root, sum, cur_sum, path, res);
        return res;
    }
    
    void dfs(TreeNode *cur, int sum, int cur_sum, vector<int> &path, vector<vector<int>> &res) {
        if (!cur)   return;
        cur_sum += cur->val;
        path.push_back(cur->val);
        if (!cur->left && !cur->right && cur_sum==sum)
            res.push_back(path);
        dfs(cur->left, sum, cur_sum, path, res);
        dfs(cur->right, sum, cur_sum, path, res);
        path.pop_back();
    }
};
