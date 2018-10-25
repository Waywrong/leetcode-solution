//  Longest Common Prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)    return "";
        if (strs.size() == 1)    return strs[0];
        string res = "";
        int col = 0;
        while (true) {
            if (col >= strs[0].size())  return res;
            char ch = strs[0][col];
            for (int row = 1; row < strs.size(); row ++) 
                if (col>=strs[row].size() || strs[row][col]!=ch)
                    return res;
            res += ch;
            col ++;
        }
        return res;
    }
};