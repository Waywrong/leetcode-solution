//  Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = dummy;
        for (int i = 0; i <= n; i ++)
            cur = cur->next;
        while (cur) {
            p = p->next;
            cur = cur->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};