//  Letter Combinations of a Phone Number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string comb = "";
        unordered_map<int, vector<char>> table{{2,{'a','b','c'}}, {3,{'d','e','f'}},
                                               {4,{'g','h','i'}}, {5,{'j','k','l'}},
                                               {6,{'m','n','o'}}, {7,{'p','q','r','s'}},
                                               {8,{'t','u','v'}}, {9,{'w','x','y','z'}}};
        dfs(digits, table, 0, comb, res);
        return res;
    }
    
    void dfs(string &digits, unordered_map<int, vector<char>> &table,
             int cur, string &comb, vector<string> &res) {
        if (cur == digits.size()) {
            res.push_back(comb);
            return;
        }
        int n = digits[cur] - '0';
        for (auto ch : table[n]) {
            comb += ch;
            dfs(digits, table, cur+1, comb, res);
            comb.erase(comb.end()-1);
        }
    }
};