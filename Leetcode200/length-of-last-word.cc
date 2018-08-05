//  Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0, end = 0, p = s.size()-1;
        for (; p>=0 && s[p]==' '; p--);
        end = p;
        for (start=end; start>=0 && s[start]!=' '; start --);
        return end - start;
    }
};