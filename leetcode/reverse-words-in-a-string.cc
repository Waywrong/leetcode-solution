//  Reverse Words in a String

class Solution {
public:
    void reverseWords(string &s) {
        while (!s.empty() && s[0]==' ')
            s.erase(s.begin());
        reverse(s.begin(), s.end());
        while (!s.empty() && s[0]==' ')
            s.erase(s.begin());
        size_t start = 0, end;
        while (start != s.size()) {
            end = start + 1;
            while (end!=s.size() && s[end]!=' ')
                ++ end;
            reverse(s.begin()+start, s.begin()+end);
            if (end == s.size())    break;
            start = end + 1;
            while (s[start] == ' ')
                s.erase(s.begin() + start);
        }
    }
};