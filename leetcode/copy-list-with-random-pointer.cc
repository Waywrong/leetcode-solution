//  Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> map;
        RandomListNode *dummy = new RandomListNode(-1), *p = dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            p->next = new RandomListNode(cur->label);
            p = p->next;
            map[cur] = p;
        }
        RandomListNode *p1 = head, *p2 = dummy->next;
        while (p1 && p2) {
            p2->random = map[p1->random];
            p1 = p1->next;
            p2 = p2->next;
        }
        return dummy->next;
    }
};
