//  Sudoku Solver

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> emptyCells;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.emplace_back(i, j);
                }
            }
        }
        
        backtracing(emptyCells, 0, board);
        board = res;     
    }
private:
    vector<vector<char>> res;
    void backtracing(vector<pair<int, int>>& emptyCells, int index, vector<vector<char>>& board) {
        if (index == emptyCells.size()) {
            res = board;
            return;
        }
        
        int x = emptyCells[index].first;
        int y = emptyCells[index].second;
        unordered_set<char> candidates = findCandidates(board, x, y);
        for (auto candidate : candidates) {
            board[x][y] = candidate;
            backtracing(emptyCells, index+1, board);
            board[x][y] = '.';
        }
    }
    
    unordered_set<char> findCandidates(vector<vector<char>>& board, int x, int y) {
        int subBoxX = (x/3)*3;
        int subBoxY = (y/3)*3;
        unordered_set<char> s({'1', '2', '3', '4', '5', '6', '7', '8', '9'});
        
        for (int i=0; i<9; i++) {
            if (board[x][i] != '.') {
                s.erase(board[x][i]);
            }
            if (board[i][y] != '.') {
                s.erase(board[i][y]);
            }
            int x_ = subBoxX+i/3;
            int y_ = subBoxY+i%3;
            if (board[x_][y_] != '.') {
                s.erase(board[x_][y_]);
            }
        }
        return s;
    }
};
