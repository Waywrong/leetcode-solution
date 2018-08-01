//  Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        TreeNode *p = root, *free = nullptr;
        while (p) {
            free = p->left;
            if (free) {
                while (free->right && free->right!=p)
                    free = free->right;
                if (!free->right) {
                    free->right = p;
                    p = p->left;
                    continue;
                }
                else
                    free->right = nullptr;
            }
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};