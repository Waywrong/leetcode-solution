//  Word Break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); i ++) {
            for (int j = 0; j <= i; j ++) {
                string temp = s.substr(j, i-j+1);
                if (dp[j] && find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
