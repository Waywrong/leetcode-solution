//  Balanced Binary Tree

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
    bool isBalanced(TreeNode* root) {
        if (!root)  return true;
        return get_height(root) >= 0;
    }
    
    int get_height(TreeNode *root) {
        if (!root)  return 0;
        int l = get_height(root->left);
        int r = get_height(root->right);
        if (l==-1 || r==-1 || abs(l - r) > 1)
            return -1;
        else
            return max(l,r) + 1;
    }
};