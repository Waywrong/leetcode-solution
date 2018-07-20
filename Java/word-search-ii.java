//  Word Search II

// Time O(K*M^2*N^2), Space O(1)
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> res = new ArrayList<String>();
        if (board.length == 0)  return res;
        if (board[0].length == 0)   return res;
        for (String w : words) {
            if (res.indexOf(w) != -1)   continue;
            if (exist(board, w))
                res.add(w);
        }
        return res;
    }
    
    private boolean exist(char[][] board, String word) {
        for (int i=0; i<board.length; i++)
            for (int j=0; j<board[0].length; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int x, int y, int start) {
        if (start == word.length()) return true;
        if (x<0 || x>=board.length || y<0 || y>=board[0].length)    return false;
        if (board[x][y] != word.charAt(start))  return false;
        char temp = board[x][y];
        board[x][y] = '#';
        if (dfs(board, word, x-1, y, start+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x+1, y, start+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x, y-1, start+1)) {
            board[x][y] = temp;
            return true;
        }
        if (dfs(board, word, x, y+1, start+1)) {
            board[x][y] = temp;
            return true;
        }
        board[x][y] = temp;
        return false;
    }
}