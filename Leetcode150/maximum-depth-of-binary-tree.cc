//  Maximum Depth of Binary Tree

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
    int maxDepth(TreeNode* root) {
        if (!root)  return 0;
        int l_h = maxDepth(root->left);
        int r_h = maxDepth(root->right);
        return (l_h>r_h) ? (l_h+1) : (r_h+1);
    }
};
