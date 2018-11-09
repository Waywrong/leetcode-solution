//  Diameter of Binary Tree

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
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        return max(max(l, r), depth(root->left) + depth(root->right));
    }
};