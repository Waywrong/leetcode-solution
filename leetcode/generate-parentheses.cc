//  Generate Parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";
        dfs(n, n, temp, res);
        return res;
    }
    
    void dfs(int n1, int n2, string &temp, vector<string> &res) {
        if (n1==0 && n2==0) {
            res.push_back(temp);
            return;
        }
        if (n1 > 0) {
            temp += '(';
            dfs(n1-1, n2, temp, res);
            temp.erase(temp.size()-1);
        }
        if (n2 > n1) {
            temp += ')';
            dfs(n1, n2-1, temp, res);
            temp.erase(temp.size()-1);
        }
    }
};
