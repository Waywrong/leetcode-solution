//  Word Search

// Time O(M^2*N^2), Space O(1)
class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0)  return false;
        if (board[0].length == 0)   return false;
        for (int x = 0; x < board.length; x ++)
            for (int y = 0; y < board[0].length; y ++)
                if (dfs(board, word, x, y, 0))
                    return true;
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int x, int y, int index) {
        if (index == word.length())   return true;
        if (x<0 || x>=board.length || y<0 || y>=board[0].length)    return false;
        if (board[x][y] != word.charAt(index))  return false;
        char temp = board[x][y];
        board[x][y] = '#';
        if (dfs(board, word, x-1, y, index+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x+1, y, index+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x, y-1, index+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x, y+1, index+1)) {
            board[x][y] = temp;
            return true;
        }
        board[x][y] = temp;
        return false;
    }
}