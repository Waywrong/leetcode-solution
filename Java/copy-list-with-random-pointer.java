//  Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */

// Time O(N), Space O(N)
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        Map<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();
        RandomListNode dummy = new RandomListNode(-1);
        RandomListNode p = dummy, cur = null;
        for (cur = head; cur != null; cur = cur.next) {
            p.next = new RandomListNode(cur.label);
            p = p.next;
            map.put(cur, p);
        }
        p = dummy.next; cur = head;
        while (cur != null) {
            p.random = map.get(cur.random);
            p = p.next;
            cur = cur.next;
        }
        return dummy.next;
    }
}