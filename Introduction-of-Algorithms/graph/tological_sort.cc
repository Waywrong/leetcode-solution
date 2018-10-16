/* Tological Sort */

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<int> tological_sort(vector<pair<int, int> > &node_pairs, int N)
{
    vector<int> counter(N, 0);
    vector<vector<int> > graph(N);
    for (auto &x : node_pairs)
    {
        counter[x.second] ++;
        graph[x.first].push_back(x.second);
    }
    vector<int> order;
    queue<int> q;
    for (int i = 0; i < N; ++ i)
        if (counter[i] == 0)    
            q.push(i);
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        order.push_back(tmp);
        for (auto &x : graph[tmp])
        {
            counter[x] --;
            if (counter[x] == 0)
                q.push(x);
        }
    }
    if (order.size() == N)  return order;
    else    return vector<int>();
}

int main(int argc, char **argv)
{
    vector<pair<int, int> > node_pairs = {{0,1},{1,2},{1,3},{2,3}};
    vector<int> order = tological_sort(node_pairs, 4);
    for (auto &x : order)   cout << x << "\t";
    cout << endl;
    return 0;
}