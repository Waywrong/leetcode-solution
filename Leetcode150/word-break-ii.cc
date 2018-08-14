//  Word Break II

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        vector<vector<bool>> segment(s.length(), vector<bool>(s.length(), false));
        dp[0] = true;
        for (int i = 0; i < s.length(); i ++) {
            for (int j = 0; j <= i; j ++) {
                string temp = s.substr(j, i-j+1);
                if (dp[j] && find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()) {
                    dp[i+1] = true;
                    segment[j][i] = true;
                }
            }
        }
        vector<string> res;
        vector<string> comb;
        dfs(s, 0, segment, comb, res);
        return res;
    }
    
    void dfs(string &s, int cur, vector<vector<bool>> &segment, vector<string> &comb, vector<string> &res) {
        if (cur == s.length()) {
            string temp = "";
            for (auto &word : comb)
                temp += word + " ";
            temp.erase(temp.end()-1);
            res.push_back(temp);
        }
        for (int i = cur; i < s.length(); i ++) {
            if (segment[cur][i]) {
                comb.push_back(s.substr(cur, i-cur+1));
                dfs(s, i+1, segment, comb, res);
                comb.pop_back();
            }
        }
    }
};
