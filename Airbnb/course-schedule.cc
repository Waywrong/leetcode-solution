//  Course Schedule

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        unordered_map<int, int> counter;
        build_graph(numCourses, prerequisites, graph, counter);
        vector<int> sorted;
        queue<int> q;
        for (auto &x : counter)
            if (x.second == 0)
                q.push(x.first);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            sorted.push_back(temp);
            for (auto &x : graph[temp]) {
                counter[x] --;
                if (counter[x] == 0)
                    q.push(x);
            }
        }
        return sorted.size() == numCourses;
    }
    
    void build_graph(int numCourses, vector<pair<int, int>> &prerequisites, vector<vector<int>> &graph, 
                     unordered_map<int, int> &counter) {
        for (int i=0; i<numCourses; i++)
            counter[i] = 0;
        for (auto &x : prerequisites) {
            graph[x.first].push_back(x.second);
            counter[x.second] ++;
        }
    }
};