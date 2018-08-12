//  Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)  return nullptr;
        k %= get_length(head);
        if (k == 0)   return head;
        ListNode *cur = head, *tail = head;
        for (int i = 0; i < k; i ++)    tail = tail->next;
        while (tail->next) {
            tail = tail->next;
            cur = cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
    
    int get_length(ListNode *head) {
        int len = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
            len ++;
        return len;
    }
};
