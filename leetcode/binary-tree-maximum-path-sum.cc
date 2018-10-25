//  Binary Tree Maximum Path Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSum(root, max_sum);
        return max_sum;
    }
    
    int maxPathSum(TreeNode *root, int &max_sum) {
        if (!root)  return 0;
        int l = maxPathSum(root->left, max_sum);
        int r = maxPathSum(root->right, max_sum);
        int sum = root->val;
        if (l > 0)  sum += l;
        if (r > 0)  sum += r;
        max_sum = max(max_sum, sum);
        return max(l, r)>0 ? max(l, r) + root->val : root->val;
    }
};
