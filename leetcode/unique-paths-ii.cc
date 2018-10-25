//  Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1])
            return 0;
        vector<int> C(n, 0);
        for (int i=0; i<m; i++) {
            C[0] = (obstacleGrid[i][0] || (C[0]==0 && i>0)) ? 0 : 1;
            for (int j=1; j<n; j++)
                C[j] = (obstacleGrid[i][j]) ? 0 : (C[j]+C[j-1]);
        }
        return C[n-1];
    }
};
