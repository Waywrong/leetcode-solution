//  Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)  return nullptr;
        ListNode *pre = nullptr, *chaser = head, *runner = head;
        while (runner->next && runner->next->next) {
            pre = chaser;
            chaser = chaser->next;
            runner = runner->next->next;
        }
        if (pre)    pre->next = nullptr;
        TreeNode *root = new TreeNode(chaser->val);
        root->left = sortedListToBST(pre ? head : nullptr);
        root->right = sortedListToBST(chaser->next);
        return root;
    }
};
