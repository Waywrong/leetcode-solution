/* Graph DFS, BFS */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<vector<int> > G;

void construct_graph(vector<pair<int, int> > &node_pairs, int N)
{
    G.resize(N);
    for (int i = 0; i < N; ++ i)    G[i] = {};
    for (auto &x : node_pairs)
        G[x.first].push_back(x.second);
}

void BFS(int start)
{
    vector<bool> visited(G.size(), false);
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << "\t";
        for (auto &x : G[tmp])
            if (!visited[x]) { q.push(x); visited[x] = true; }
    }
}

void DFS(int start, vector<bool> &visited)
{
    cout << start << "\t";
    visited[start] = true;
    for (auto &x : G[start])
        if (!visited[x])
            DFS(x, visited);
}

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<pair<int, int> > node_pairs = {{0,1}, {1,2}, {0,2}};
    vector<bool> visited(N, false);
    construct_graph(node_pairs, N);
    DFS(0, visited);
    return 0;
}