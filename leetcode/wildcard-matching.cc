//  Wildcard Matching

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); i ++)
            dp[0][i] = (dp[0][i-1] && p[i-1]=='*');
        for (int i = 1; i <= s.length(); i ++) {
            for (int j = 1; j <= p.length(); j ++) {
                if (s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*')
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
        }
        return dp[s.length()][p.length()];
    }
};
