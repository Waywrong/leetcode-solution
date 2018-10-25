//  Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *p1, *p2, *nxt;
        while (pre->next && pre->next->next) {
            p1 = pre->next;
            p2 = pre->next->next;
            nxt = pre->next->next->next;
            pre->next = p2;
            p2->next = p1;
            p1->next = nxt;
            pre = p1;
        }
        return dummy->next;
    }
};