//  Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>> &grid, int x, int y) {
        if (x<0 || y<0 || x>=grid.size() || y>=grid[0].size()
            || grid[x][y]=='0' || grid[x][y]=='2')
            return;
        if (grid[x][y] == '1')
            grid[x][y] = '2';
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }
};