//  Flatten Binary Tree to Linked List

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
    void flatten(TreeNode* root) {
        if (!root)  return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            if (cur->right) st.push(cur->right);
            if (cur->left)  st.push(cur->left);
            cur->left = nullptr;
            if (!st.empty())    cur->right = st.top();
        }
    }
};
