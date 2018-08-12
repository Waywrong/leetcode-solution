//  Insertion Sort List

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)   return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *p = head, *cur = head->next, *tail = head;
        while (cur) {
            for (; p->val<cur->val && p!=cur; p=p->next)  pre = p;
            if (p == cur) 
                tail = cur;
            else {
                tail->next = cur->next;
                pre->next = cur;
                cur->next = p;
            }
            cur = tail->next;
            pre = dummy;
            p = pre->next;
        }        
        return dummy->next;
    }
};
