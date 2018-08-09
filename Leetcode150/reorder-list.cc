//  Reorder List

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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *cur = head;
        while (cur->next) {
            cur->next = reverseList(cur->next);
            cur = cur->next;
        }
    }
    
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr, *cur = head, *nxt;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
