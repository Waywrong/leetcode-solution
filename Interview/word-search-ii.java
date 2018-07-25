//  Word Search II

// Time O(K*M^2*N^2), Space O(1)
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<String>();
        for (String word : words)
            if (exist(board, word) && res.indexOf(word)==-1)
                res.add(word);
        return res;
    }
    
    private boolean exist(char[][] board, String word) {
        int m = board.length;
        if (m == 0) return false;
        int n = board[0].length;
        if (n == 0) return false;
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++)
                if (dfs(board, word, 0, i, j))
                    return true;
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int len, int x, int y) {
        if (len == word.length())   return true;
        if (x<0 || x>=board.length || y<0 || y>=board[0].length)    return false;
        if (board[x][y] != word.charAt(len))    return false;
        char temp = board[x][y];
        board[x][y] = '*';
        if (dfs(board, word, len+1, x-1, y)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, len+1, x+1, y)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, len+1, x, y-1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, len+1, x, y+1)) {
            board[x][y] = temp;
            return true;
        }
        board[x][y] = temp;
        return false;
    }
}