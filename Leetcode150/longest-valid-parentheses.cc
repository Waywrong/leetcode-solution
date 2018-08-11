//  Longest Valid Parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        vector<int> C(s.length()+1, 0);
        for (int i=1; i<=s.length(); i++) {
            if (s[i-1]!=')' || i<2)    continue;
            if (s[i-2] == '(' )
                C[i] = C[i-2] + 2;
            else if (i-C[i-1]-1>0 && s[i-C[i-1]-2]=='(' && C[i-1]>0)
                C[i] = C[i-1] + 2 + C[i-C[i-1]-2];
            max_len = max(max_len, C[i]);
        }
        return max_len;
    }
};
