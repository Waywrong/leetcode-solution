/* Common Tree */

#include <iostream>
#include <vector>
#include <queue>
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
tree_node<T> *construct_tree(vector<pair<T, T> > &node_pairs)
{
    unordered_map<T, T> umap;
    unordered_map<T, tree_node<T> *> nodes;
    unordered_set<T> s;
    for(auto &p : node_pairs)
    {
        T parent = p.first, child = p.second;
        s.insert(child);
        if (nodes.count(parent)==0)
            nodes[parent] = new tree_node<T>(parent);
        if (nodes.count(child) == 0)
            nodes[child] = new tree_node<T>(child);
        if (umap.count(parent) == 0)
            nodes[parent]->child = nodes[child];
        else
            nodes[umap[parent]]->brother = nodes[child];
        umap[parent] = child;
    }
    /* find root */
    for (auto &p : nodes)
        if (s.find(p.first) == s.end())
            return nodes[p.first];
    cout << "Invalid Input..." << endl;
    return 0;
}

template<typename T>
void traversal(tree_node<T> *root)
{
    if (root == 0)
    {
        cout << "Empty Tree..." << endl;
        return;
    }
    queue<tree_node<T> *> q;
    q.push(root);
    while (!q.empty())
    {
        tree_node<T> *p = q.front();
        q.pop();
        cout << p->data << "\t";
        if (p->child != 0)
            for (tree_node<T> *t = p->child; t != 0; t = t->brother)
                q.push(t);
    }
}

int main(int argc, char **argv)
{
    vector<pair<int, int> > node_pairs = { {1,2}, {1,3}, {2,4}, {2,5}, {2,6}, {3,7}, {5,8} };
    tree_node<int> *root = construct_tree(node_pairs);
    traversal(root);
    return 0;
}