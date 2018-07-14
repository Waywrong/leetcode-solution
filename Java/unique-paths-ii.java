//  Unique Paths II

// Time O(N^4), Space O(N)
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        return dfs(obstacleGrid, m, n);
    }
    
    private int dfs(int[][] obstacleGrid, int m, int n) {
        if (m<1 || n<1)
            return 0;
        if (obstacleGrid[m-1][n-1] == 1)
            return 0;
        if (m==1 && n==1)
            return 1;
        return dfs(obstacleGrid, m-1, n) + dfs(obstacleGrid, m, n-1);
    }
}

// Time O(N^2), Space O(N^2)
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] f = new int[m][n];
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                f[i][j] = 0;
        f[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        return dfs(obstacleGrid, m-1, n-1, f);
    }
    
    private int dfs(int[][] obstacleGrid, int x, int y, int f[][]) {
        if (x<0 || y<0)
            return 0;
        if (obstacleGrid[x][y] == 1)
            return 0;
        if (x==0 && y==0)
            return f[0][0];
        if (f[x][y] > 0)
            return f[x][y];
        else
            return f[x][y] = dfs(obstacleGrid, x-1, y, f) + dfs(obstacleGrid, x, y-1, f);
    }
}

// Time O(N^2), Space O(N) 
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[] f = new int[n];
        for (int i=0; i<n; i++)
            f[i] = 0;
        f[0] = (obstacleGrid[0][0]==1) ? 0 : 1;
        for (int i=0; i<m; i++) {
            f[0] = (f[0]==0) ? 0 : ((obstacleGrid[i][0]==1) ? 0 : 1);
            for (int j=1; j<n; j++)
                f[j] = (obstacleGrid[i][j]==1) ? 0 : (f[j]+f[j-1]);
        }
        return f[n-1];
    }
}