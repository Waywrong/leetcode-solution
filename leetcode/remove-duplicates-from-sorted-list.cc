//  Remove Duplicates from Sorted List

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
        unordered_map<int, int> map;
        for (ListNode *p = head; p; p = p->next)
            map[p->val] ++;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = head, *pre = dummy;
        while (cur) {
            if (map[cur->val] > 1) {
                pre->next = cur->next;
                cur = pre->next;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
