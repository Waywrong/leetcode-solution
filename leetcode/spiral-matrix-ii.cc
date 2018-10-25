//  Spiral Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int top = 0, bot = n-1, left = 0, right = n-1;
        int num = 1;
        while (true) {
            for (int i=left; i<=right; i++) res[top][i] = num++;
            if (++top > bot)    break;
            for (int i=top; i<=bot; i++)    res[i][right] = num++;
            if (--right < left) break;
            for (int i=right; i>=left; i--) res[bot][i] = num++;
            if (--bot < top)    break;
            for (int i=bot; i>=top; i--)    res[i][left] = num++;
            if (++left > right) break;
        }
        return res;
    }
};