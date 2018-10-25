//  Linked List Cycle II

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
    ListNode *detectCycle(ListNode *head) {
        if (!head)  return nullptr;
        ListNode *chaser = head, *runner = head;
        while (runner->next && runner->next->next) {
            chaser = chaser->next;
            runner = runner->next->next;
            if (runner == chaser) {
                while (head != chaser) {
                    head = head->next;
                    chaser = chaser->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};