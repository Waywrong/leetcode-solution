//  Unique Binary Search Tree II

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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0)   return vector<TreeNode *>();
        else    return generate(1, n);
    }
    
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> subtrees;
        if (start > end) {
            subtrees.push_back(nullptr);
            return subtrees;
        }
        for (int k=start; k<=end; k++) {
            vector<TreeNode *> left_subtrees = generate(start, k-1);
            vector<TreeNode *> right_subtrees = generate(k+1, end);
            for (TreeNode *i : left_subtrees) {
                for (TreeNode *j : right_subtrees) {
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subtrees.push_back(node);
                }
            }
        }
        return subtrees;
    }
};
