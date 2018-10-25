//  Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeWithSegment(preorder, 0, preorder.size()-1,
                                   inorder, 0, inorder.size()-1);
    }
    
    TreeNode *buildTreeWithSegment(vector<int> &preorder, int l1, int r1,
                                  vector<int> &inorder, int l2, int r2) {
        if (l1>r1 || l2>r2)   return nullptr;
        int root_val = preorder[l1];
        int root_idx;
        for (root_idx = 0; inorder[root_idx] != root_val; root_idx ++);
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTreeWithSegment(preorder, l1+1, l1+root_idx-l2, inorder, l2, root_idx-1);
        root->right = buildTreeWithSegment(preorder, l1+root_idx-l2+1, r1, inorder, root_idx+1, r2);
        return root;
    }
};
