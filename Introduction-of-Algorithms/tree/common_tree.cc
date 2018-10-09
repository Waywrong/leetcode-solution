/* Common Tree */

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template<typename T>
struct tree_node
{
    tree_node *child;
    tree_node *brother;
    T data;
    tree_node(T &val=T()) : child(0), brother(0), data(val) {}
};

template<typename T>
typename tree_node<T> *construct_tree(vector<pair<T, T> > &node_pairs)
{
    unordered_map<T, T> umap;
    unordered_map<T, tree_node *> nodes;
    unordered_set<T> s;
    for(auto &p : node_pairs)
    {
        T parent = p.first, child = p.second;
        s.insert(parent);
        s.insert(child);
        if (nodes.count(parent)==0)
            nodes[parent] = new tree_node(parent);
        if (nodes.count(child) == 0)
            nodes[child] = new tree_node(child);
        if (umap.count(parent) == 0)
            nodes[parent]->child = nodes[child];
        else
            nodes[umap[parent]]->brother = nodes[child];
        nodes[parent] = nodes[child];
    }
    /* find root */
    for (auto &p : nodes)
        if (s.find(p.first) == s.end())
            return nodes[p.first];
}

int main(int argc, char **argv)
{
    return 0;
}