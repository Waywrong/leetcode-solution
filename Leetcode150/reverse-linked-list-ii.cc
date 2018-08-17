//  Reverse Linked List II

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *start = new ListNode(-1); start->next = head;
        ListNode *pre = start, *cur = head, *nxt;
        ListNode *tail, *pre_tail;
        int step = 1;
        while (step < m)  { pre = cur; cur = cur->next; step ++; }
        tail = cur; pre_tail = pre;
        while (step <= n) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            step ++;
        }
        pre_tail->next = pre;   tail->next = cur;
        return start->next;
    }
};
