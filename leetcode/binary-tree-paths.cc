//  Binary Tree Paths

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
    string vec2str(vector<int> &path) {
        string res;
        for (auto &x : path) {
            if (res.empty())
                res += to_string(x);
            else
                res = res + "->" + to_string(x);
        }
        return res;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<int> path;
        stack<TreeNode*> s;
        if (root == nullptr)
            return paths;
        TreeNode *p = root, *last = nullptr;
        while (p != nullptr) {
            s.push(p);
            path.push_back(p->val);
            p = p->left;
        }
        while (!s.empty()) {
            p = s.top();
            if (p->right == nullptr || p->right == last) {
                if (p->left == nullptr && p->right == nullptr)
                    paths.push_back(vec2str(path));
                s.pop();
                path.pop_back();
                last = p;
            }
            else {
                p = p->right;
                while (p != nullptr) {
                    s.push(p);
                    path.push_back(p->val);
                    p = p->left;
                }
            }
        }
        return paths;
    }
};