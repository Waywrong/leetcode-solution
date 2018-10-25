//  Sum Root to Leaf Numbers

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
    int sumNumbers(TreeNode* root) {
        if (!root)  return 0;
        int res = 0;
        TreeNode *cur = root, *last = nullptr;
        stack<TreeNode *> st;
        int cur_sum = 0;
        while (cur) {
            st.push(cur);
            cur_sum = cur_sum * 10 + cur->val;
            cur = cur->left;
        }
        while (!st.empty()) {
            cur = st.top();
            if (!cur->right || cur->right==last) {
                if (!cur->left && !cur->right) 
                    res += cur_sum;
                st.pop();
                last = cur;
                cur_sum /= 10;
            }
            else {
                cur = cur->right;
                while (cur) {
                    st.push(cur);
                    cur_sum = cur_sum * 10 + cur->val;
                    cur = cur->left;
                }
            }
        }
        return res;
    }
};
