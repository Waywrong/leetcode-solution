//  Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> map;
        for (auto x : flights)
            map[x[0]].emplace_back(x[1], x[2]);
        vector<int> visited(n, 0);
        int res = INT_MAX;
        dfs(src, dst, 0, K+1, res, visited, map);
        return (res == INT_MAX) ? -1 : res;
    }
    
    void dfs(int s, int t, int cost, int k, int &res,
             vector<int> &visited, unordered_map<int, vector<pair<int,int>>> &map) {
        if (s == t) {
            res = cost;
            return;
        }
        if (k == 0) return;
        visited[s] = 1;
        for (auto &x : map[s]) {
            if (visited[x.first] == 0) {
                if (cost + x.second > res)  continue;
                dfs(x.first, t, cost+x.second, k-1, res, visited, map);
            }
        }
        visited[s] = 0;
    }
};