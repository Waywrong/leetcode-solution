//  Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        for (int i = 0; i < n; i ++)
            for (int j = i+1; j < n; j ++)
                swap(matrix[i][j], matrix[j][i]);
        for (int l = 0; l < n; l ++)
            reverse(matrix[l].begin(), matrix[l].end());
    }
};
