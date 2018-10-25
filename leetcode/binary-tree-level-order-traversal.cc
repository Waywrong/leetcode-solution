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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)  return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            TreeNode *temp;
            for (int i = 0; i < size; i ++) {
                temp = q.front();   q.pop();
                vec.push_back(temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right)    q.push(temp->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};//  Binary Tree Level Order Traversal

