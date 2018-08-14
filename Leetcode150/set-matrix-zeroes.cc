//  Set Matrix Zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0)
            return;
        unordered_set<int> rows, cols;
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[i].size(); j ++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto &r : rows) 
            for (int i = 0; i < matrix[0].size(); i ++)
                matrix[r][i] = 0;
        for (auto &c : cols)
            for (int i = 0; i < matrix.size(); i ++)
                matrix[i][c] = 0;
    }
};
