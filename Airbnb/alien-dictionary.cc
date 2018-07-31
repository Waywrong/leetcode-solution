//  Alien Dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        if (words.size() == 0)  return res;
        vector<vector<int>> graph(26, vector<int>());
        unordered_map<int, int> counter;
        if (!create_graph(words, graph, counter))
            return res;
        queue<int> q;
        for (auto x : counter)
            if (x.second == 0)
                q.push(x.first);
        while (!q.empty()) {
            int t = q.front();  q.pop();
            for (auto x : graph[t]) {
                counter[x] --;
                if (counter[x] == 0)
                    q.push(x);
            }
            res.push_back(t + 'a');
        }
        for (auto x : counter)
            if (x.second != 0)
                return "";
        return res;
    }
    
private:
    bool create_graph(vector<string> &words, vector<vector<int>> &graph, unordered_map<int, int> &counter) {
        for (auto word : words)
            for (auto w : word)
                counter[w - 'a'] = 0;
        for (int i=1; i<words.size(); i++) {
            int j = 0;
            while (j<words[i-1].size() && j<words[i].size() && words[i-1][j]==words[i][j])  
                j ++;
            if (j<words[i-1].size() && j==words[i].size())  return false;
            if (j<words[i-1].size() && j<words[i].size()) {
                graph[words[i-1][j] - 'a'].push_back(words[i][j] - 'a');
                counter[words[i][j] - 'a'] ++;
            }
        }
        return true;
    }
};