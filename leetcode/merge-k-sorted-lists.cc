//  Merge K Sorted Lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        if (lists.size() == 1)  return lists[0];
        while (lists.size() > 1) {
            ListNode *l1 = lists[0], *l2 = lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(mergeSortedLists(l1, l2));
        }
        return lists[0];
    }
    
    ListNode *mergeSortedLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
            return l1 ? l1 : l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *p1 = l1, *p2 = l2, *p = dummy;
        ListNode *temp;
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
};