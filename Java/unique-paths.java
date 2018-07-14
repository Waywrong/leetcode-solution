//  Unique Paths

// Time O(N^4), Space O(1)
class Solution {
    public int uniquePaths(int m, int n) {
        if (m<1 || n<1)
            return 0;
        if (m==1 && n==1)
            return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
}

// Time O(N^2), Space O(N^2)
class Solution {
    private List<List<Integer>> f;
    
    public int uniquePaths(int m, int n) {
        f = new ArrayList<List<Integer>>();
        for (int i=0; i<m; i++) {
            f.add(new ArrayList<Integer>());
            for (int j=0; j<n; j++)
                f.get(i).add(0);
        }
        f.get(0).set(0, 1);
        int ans = dfs(m-1, n-1);
        return ans;
    }
    
    private int dfs(int x, int y) {
        if (x<0 || y<0)
            return 0;
        if (x==0 && y==0)
            return f.get(0).get(0);
        if (f.get(x).get(y) > 0)
            return f.get(x).get(y);
        int temp = dfs(x-1, y) + dfs(x, y-1);
        f.get(x).set(y, temp);
        return f.get(x).get(y);
    }
}

// Time O(N^2), Space O(N)
class Solution {
    public int uniquePaths(int m, int n) {
        List<Integer> f = new ArrayList<Integer>();
        for (int i=0; i<n; i++)
            f.add(0);
        f.set(0, 1);
        for (int i=0; i<m; i++) 
            for (int j=1; j<n; j++)
                f.set(j, f.get(j) + f.get(j-1));
        return f.get(n-1);
    }
}