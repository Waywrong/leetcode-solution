//  Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0)   return res;
        res.push_back(vector<int> { 1 });
        if (numRows == 1)   return res;
        res.push_back(vector<int> { 1, 1 });
        if (numRows == 2)   return res;
        for (int i=2; i<numRows; i++) {
            vector<int> vec(i+1);
            vec[0] = vec[i] = 1;
            for (int j=1; j<i; j++)
                vec[j] = res[i-1][j-1] + res[i-1][j];
            res.push_back(vec);
        }
        return res;
    }
};