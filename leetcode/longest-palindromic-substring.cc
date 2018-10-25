//  Longest Palindromic Substring

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())  return "";
        int n = s.length();
        int l = 0, r = 0, max_len = 0;
        vector<vector<bool>> C(n, vector<bool>(n, false));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (s[i]==s[j] && (i-j<2 || C[j+1][i-1])) {
                    C[j][i] = true;
                    if (i-j+1 > max_len) {
                        max_len = i - j + 1;
                        l = j;
                        r = i;
                    }
                }
            }
        }
        return s.substr(l, max_len);
    }
};
