//  Clone Graph

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int, UndirectedGraphNode*> map;
        return clone(node, map);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &map) {
        if (!node) return node;
        if (map.count(node->label)) return map[node->label];
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        map[node->label] = new_node;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            (new_node->neighbors).push_back(clone(node->neighbors[i], map));
        }
        return new_node;
    } 
};
