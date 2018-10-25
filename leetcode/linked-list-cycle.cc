//  Linke List Cycle

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
    bool hasCycle(ListNode *head) {
        if (!head)  return false;
        ListNode *chaser = head, *runner = head;
        while (runner->next && runner->next->next) {
            chaser = chaser->next;
            runner = runner->next->next;
            if (chaser == runner)   
                return true;
        }
        return false;
    }
};