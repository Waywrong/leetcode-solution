//  Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if (numCourses <= 0)    return res;
        if (prerequisites.size() == 0) {
            for (int i=0; i<numCourses; i++)
                res.push_back(i);
            return res;
        }
        vector<vector<int>> graph(numCourses, vector<int>());
        unordered_map<int, int> counter;
        for (int i=0; i<numCourses; i++)
            counter[i] = 0;
        for (auto &pair : prerequisites) {
            graph[pair.second].push_back(pair.first);
            counter[pair.first] ++;
        }
        queue<int> q;
        for (auto &x : counter) 
            if (x.second == 0)
                q.push(x.first);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            for (auto &x : graph[temp]) {
                counter[x] --;
                if (counter[x] == 0)
                    q.push(x);
            }
        }
        if (res.size() != numCourses)
            return vector<int>();
        return res;
    }
};