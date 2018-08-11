//  Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *p = pre->next, *nxt = nullptr;
        int len = get_length(p);
        while (len >= k) {
            for (int i = 0; i < k-1; i ++) {
                p = p->next;
                nxt = p->next;
            }
            ListNode *tmp = pre->next;
            reverse_list(tmp, k);
            tmp->next = nxt;
            pre->next = p;
            pre = tmp;
            p = nxt;
            len = get_length(p);
        }
        return dummy->next;
    }
    
    void reverse_list(ListNode *head, int k) {
        if (!head || !head->next)   return;
        ListNode *pre = nullptr, *cur = head, *nxt;
        for (int i = 0; i < k; i ++) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
    }
    
    int get_length(ListNode *head) {
        int len = 0;
        for (ListNode *p = head; p; p = p->next)
            len ++;
        return len;
    }
};
