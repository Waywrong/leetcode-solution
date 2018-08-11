//  Unique Paths

//  Solution1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> C(n, 1);
        for (int i=1; i<m; i++) 
            for (int j=1; j<n; j++)
                C[j] += C[j-1];
        return C[n-1];
    }
};

//  Solution 2
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> C(m, vector<int>(n, 0));
        C[0][0] = 1;
        return dfs(m-1, n-1, C);
    }
    
    int dfs(int x, int y, vector<vector<int>> &C) {
        if (x<0 || y<0) return 0;
        if (x==0 && y==0)   return C[x][y];
        if (C[x][y])
            return C[x][y];
        else
            return C[x][y] = dfs(x-1, y, C) + dfs(x, y-1, C);
    }
};
