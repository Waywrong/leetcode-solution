//  N-Queens

// Time O(N*N!), Space O(N)
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<List<String>>();
        int[] C = new int[n];
        for (int i=0; i<n; i++)
            C[i] = -1;
        dfs(n, 0, C, ans);
        return ans;
    }
    
    private void dfs(int n, int row, int[] C, List<List<String>> ans) {
        if (row == n) {
            List<String> l = new ArrayList<String>();
            for (int i=0; i<n; i++) {
                char[] ch = new char[n];
                Arrays.fill(ch, '.');
                ch[C[i]] = 'Q';
                l.add(new String(ch));
            }
            ans.add(l);
            return;
        }
        for (int col=0; col<n; col++) {
            if (!isValid(C, row, col))
                continue;
            C[row] = col;
            dfs(n, row+1, C, ans);
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