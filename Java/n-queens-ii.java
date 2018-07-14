//  N-Queens II

// Time O(N!), Space O(1)
class Solution {
    private int ans = 0;
    
    public int totalNQueens(int n) {
        int[] C = new int[n];
        Arrays.fill(C, -1);
        dfs(n, 0, C);
        return this.ans;
    }
    
    private void dfs(int n, int row, int[] C) {
        if (row == n) {
            this.ans ++;
            return;
        }
        for (int col=0; col<n; col ++) {
            if (!isValid(C, row, col))
                continue;
            C[row] = col;
            dfs(n, row+1, C);
            C[row] = -1;
        }
    }
    
    private Boolean isValid(int[] C, int row, int col) {
        for (int i=0; i<row; i++) 
            if (col==C[i] || Math.abs(i-row)==Math.abs(C[i]-col))
                return false;
        return true;
    }
}