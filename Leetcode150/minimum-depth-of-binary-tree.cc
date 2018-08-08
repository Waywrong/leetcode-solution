//  Minimum Depth of Binary Tree

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
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        int l_h = minDepth(root->left);
        int r_h = minDepth(root->right);
        if (l_h==0 || r_h==0)
            return max(l_h, r_h) + 1;
        else
            return min(l_h, r_h) + 1;
    }
};

// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)  return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                TreeNode *t = q.front();
                q.pop();
                if (!t->left && !t->right)
                    return res;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res ++;
        }
        return res;
    }
};
