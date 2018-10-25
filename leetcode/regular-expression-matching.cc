//  Regular Expression Expression

/* Solution 2 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0)  return s.size()==0;
        if (p.size() == 1)  
            return (s.size()==1 && (p[0]==s[0] || p[0]=='.'));
        if (p[1] != '*') {
            if (s.size() == 0)  return false;
            return (p[0]==s[0] || p[0]=='.') && isMatch(s.substr(1), p.substr(1));
        }
        while (s.size()!=0 && (p[0]==s[0] || p[0]=='.')) {
            if (isMatch(s, p.substr(2)))    return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};

/* Solution 2 */
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+1, vector<bool>(p.length()+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); i ++)
            dp[0][i] = i>1 && p[i-1]=='*' && dp[0][i-2];
        for (int i = 1; i <= s.length(); i ++) {
            for (int j = 1; j <= p.length(); j ++) {
                if (p[j-1] != '*')
                    dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                else
                    dp[i][j] = (dp[i][j-2]) || ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
            }
        }
        return dp[s.length()][p.length()];
    }
};
