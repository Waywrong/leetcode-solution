//  Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i<1 && j<1) continue;
                else if (i<1 || j<1)
                    grid[i][j] += (i<1) ? grid[i][j-1] : grid[i-1][j];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
