//  Palindrome Linked List

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
    ListNode *reverseList(ListNode *head) {
        if (head==nullptr || head->next==nullptr)
            return head;
        ListNode *pre = nullptr, *cur = head, *nxt = nullptr;
        while (cur != nullptr) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    
    int getLength(ListNode *head) {
        int res = 0;
        for (auto p = head; p; p = p->next)
            ++ res;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        int len = getLength(head);
        ListNode *pre = nullptr, *cur = head;
        for (int i = 0; i < len/2; ++ i) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = nullptr;
        cur = reverseList(cur);
        for (auto p1=head, p2=cur; p1 && p2; p1=p1->next, p2=p2->next)
            if (p1->val != p2->val)
                return false;
        return true;
    }
};