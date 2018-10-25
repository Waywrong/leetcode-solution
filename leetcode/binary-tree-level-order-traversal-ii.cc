//  Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            int n = q.size();
            for (int i=0; i<n; i++) {
                TreeNode *t = q.front();
                q.pop();
                vec.push_back(t->val);
                if (t->left)    q.push(t->left);
                if (t->right)   q.push(t->right);
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
