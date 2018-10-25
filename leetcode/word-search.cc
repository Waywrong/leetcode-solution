//  Word Search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size()==0 || board[0].size()==0)  
            return false;
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[0].size(); j++)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }
    
    bool dfs(vector<vector<char>> &board, string &word, int index, int x, int y) {
        if (index == word.size())   return true;
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size())    
            return false;
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
