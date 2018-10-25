//  Palindrome Partitioning

//  Solution 1
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(s, 0, part, res);
        return res;
    }
    
    void dfs(string &s, int cur, vector<string> &part, vector<vector<string>> &res) {
        if (cur == s.length()) {
            res.push_back(part);
            return;
        }
        for (int i = cur; i < s.length(); i ++) {
            string temp = s.substr(cur, i-cur+1);
            if (is_palindrome(temp)) {
                part.push_back(temp);
                dfs(s, i+1, part, res);
                part.pop_back();
            }
        }
    }
    
    bool is_palindrome(string &s) {
        int l = 0, r = s.length()-1;
        while (l < r) 
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};

//  Solution 2
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> C(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; i --) 
            for (int j = i; j < n; j ++)
                if (s[i]==s[j] && (j-i<2 || C[i+1][j-1]))
                    C[i][j] = true;
        vector<vector<string>> sub_palind_str[n];
        for (int i = n-1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (C[i][j]) {
                    string palind = s.substr(i, j-i+1);
                    if (j == n-1)   
                        sub_palind_str[i].push_back(vector<string> { palind });
                    else {
                        for (auto x : sub_palind_str[j+1]) {
                            x.insert(x.begin(), palind);
                            sub_palind_str[i].push_back(x);
                        }
                    }
                }
            }
        }
        return sub_palind_str[0];
    }
};
