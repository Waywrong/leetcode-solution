//  Sort List

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)   return head;
        int len = get_length(head);
        ListNode *p = head, *pre = nullptr;
        for (int i=0; i<len/2; i++) {
            pre = p;
            p = p->next;
        }
        pre->next = nullptr;
        head = sortList(head);
        p = sortList(p);
        return mergeSortedLists(head, p);
    }
    
    ListNode *mergeSortedLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *p1 = l1, *p2 = l2, *temp;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                temp = p1->next;
                p->next = p1;
                p1 = temp;
            }
            else {
                temp = p2->next;
                p->next = p2;
                p2 = temp;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return dummy->next;
    }
    
    int get_length(ListNode *head) {
        int res = 0;
        for (ListNode *p=head; p; p=p->next)
            res ++;
        return res;
    }
};