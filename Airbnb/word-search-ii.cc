//  Word Search II

// Time O(K*M^2*N^2), Space O(1)
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for (string &word : words) 
            if (hasWord(board, word) && find(res.begin(), res.end(), word)==res.end())
                res.push_back(word);
        return res;
    }
    
    bool hasWord(vector<vector<char>> &board, string &word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y) {
        if (index == word.size())   return true;
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size())    return false;
        if (board[x][y] != word[index]) return false;
        char temp = board[x][y];
        board[x][y] = '*';
        if (dfs(board, word, index+1, x-1, y)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, index+1, x+1, y)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, index+1, x, y-1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, index+1, x, y+1)) {
            board[x][y] = temp;
            return true;
        }
        board[x][y] = temp;
        return false;
    }
};