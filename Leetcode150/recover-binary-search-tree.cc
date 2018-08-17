//  Recover Binary Search Tree

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
    void recoverTree(TreeNode* root) {
        traversal(root);
        swap(first->val, second->val);
    }
    
    void traversal(TreeNode *root) {
        if(root==nullptr)
            return;
        traversal(root->left);
        if(first==nullptr && prev->val>=root->val)
            first = prev;
        if(first!=nullptr && prev->val>=root->val)
            second = root;
        prev = root;
        traversal(root->right);
    }
    
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = new TreeNode(INT_MIN);
};
