//  Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeWithSegment(inorder, 0, inorder.size()-1,
                                   postorder, 0, postorder.size()-1);
    }
    
    TreeNode *buildTreeWithSegment(vector<int> &inorder, int l1, int r1,
                                  vector<int> &postorder, int l2, int r2) {
        if (l1>r1 || l2>r2) return nullptr;
        int root_val = postorder[r2];
        int root_idx;
        for (root_idx = 0; inorder[root_idx]!=root_val; root_idx ++);
        TreeNode *root = new TreeNode(root_val);
        root->left = buildTreeWithSegment(inorder, l1, root_idx-1, postorder, l2, l2+root_idx-l1-1);
        root->right = buildTreeWithSegment(inorder, root_idx+1, r1, postorder, l2+root_idx-l1, r2-1);
        return root;
    }
};
