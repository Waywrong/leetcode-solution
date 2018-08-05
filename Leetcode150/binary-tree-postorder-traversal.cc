//  Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)  return res;
        stack<TreeNode *> st;
        TreeNode *p = root, *prev = nullptr;
        while (p) {
            st.push(p);
            p = p->left;
        }
        while (!st.empty()) {
            p = st.top();
            if (!p->right || p->right==prev) {
                st.pop();
                res.push_back(p->val);
                prev = p;
            }
            else {
                p = p->right;
                while (p) {
                    st.push(p);
                    p = p->left;
                }
            }
        }
        return res;
    }
};