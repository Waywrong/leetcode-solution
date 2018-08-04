//  Sliding Puzzle

/* DFS */
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int res = INT_MAX;
        string s = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) 
            + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);
        unordered_map<int, vector<int>> path {{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}};
        unordered_map<string, int> passed;
        dfs(s, path, passed, s.find('0'), s.find('0'), 0, res);
        return (res == INT_MAX) ? -1 : res;
    }
    
    void dfs(string s, unordered_map<int, vector<int>> &path, unordered_map<string, int> &passed, 
                int cur, int nxt, int steps, int &res) {
        swap(s[cur], s[nxt]);
        if (s == "123450") {
            res = min(res, steps);
            return;
        }
        if (steps<res && (passed[s]==0 || passed[s]>steps)) {
            passed[s] = steps;
            for (auto &x : path[nxt])
                dfs(s, path, passed, nxt, x, steps+1, res);
        }
    }
};

/* BFS */
class Solution {
public:
    unordered_map<int, vector<int>> moves{{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}};
    
    int slidingPuzzle(vector<vector<int>>& b) {
        string s = to_string(b[0][0]) + to_string(b[0][1]) + to_string(b[0][2])
            + to_string(b[1][0]) + to_string(b[1][1]) + to_string(b[1][2]);

        unordered_map<string, int> m({{s, 0}});
        queue<pair<string, int>> q({{s, s.find('0')}});

        for (;!q.empty() && q.front().first != "123450";q.pop()) {
            for (auto new_zero : moves[q.front().second]) {
                auto str = q.front().first;
                swap(str[q.front().second], str[new_zero]);
                if (m.insert({str, m[q.front().first] + 1}).second) 
                    q.push({ str, new_zero });
            }   
        }
        return q.empty() ? -1 : m[q.front().first];
    }
};