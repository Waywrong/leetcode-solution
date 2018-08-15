//  Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)   return head;
        int pre_num = head->val;
        ListNode *cur = head->next, *pre = head;
        while (cur) {
            if (cur->val == pre_num) {
                pre->next = cur->next;
                cur = pre->next;
            }
            else {
                pre_num = cur->val;
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
