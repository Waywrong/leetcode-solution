//  Populating Next Right Pointers in Each Node II

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        TreeLinkNode *dummy = new TreeLinkNode(-1);
        TreeLinkNode *cur = dummy;
        for (TreeLinkNode *p = root; p; p = p->next) {
            if (p->left) {
                cur->next = p->left;
                cur = cur->next;
            }
            if (p->right) {
                cur->next = p->right;
                cur = cur->next;
            }
        }
        connect(dummy->next);
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)  return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                TreeLinkNode *t = q.front();
                q.pop();
                t->next = (i==size-1) ? nullptr : q.front();
                if (t->left)    q.push(t->left);
                if (t->right)   q.push(t->right);
            }
        }
    }
};
