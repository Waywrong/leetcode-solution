//  Palindrome Partitioning II

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> cut(n+1);
        vector<vector<bool>> C(n, vector<bool>(n, false));
        for (int i = 0; i < n+1; i ++)
            cut[i] = n - i - 1;
        for (int i = n-1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (s[i]==s[j] && (j-i<2 || C[i+1][j-1])) {
                    C[i][j] = true;
                    cut[i] = min(cut[i], cut[j+1]+1);
                }
            }
        }
        return cut[0];
    }
};
