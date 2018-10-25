//  Valid Binary Search Tree

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
    bool isValidBST(TreeNode* root) {
        if (!root)  return true;
        if (root->left) {
            TreeNode *p = root->left;
            while (p->right)    p = p->right;
            if (p->val >= root->val)    
                return false;
        }
        if (root->right) {
            TreeNode *p = root->right;
            while (p->left) p = p->left;
            if (p->val <= root->val)
                return false;
        }
        return isValidBST(root->left)
            && isValidBST(root->right);
    }
};