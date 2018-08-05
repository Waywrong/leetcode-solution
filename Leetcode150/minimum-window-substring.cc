//  Minimum Window Substring

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size()<t.size())
            return "";
        const int ASCII_MAX = 256;
        int appeared_count[ASCII_MAX];
        int excepted_count[ASCII_MAX];
        fill(appeared_count, appeared_count + ASCII_MAX, 0);
        fill(excepted_count, excepted_count + ASCII_MAX, 0);
        for (auto &ch : t)  excepted_count[ch] ++;
        int min_width = INT_MAX, start = 0, end = 0, min_start = 0;
        int appeared = 0;
        for (; end < s.size(); end ++) {
            if (excepted_count[s[end]]>0) {
                appeared_count[s[end]] ++;
                if (appeared_count[s[end]] <= excepted_count[s[end]])
                    appeared ++;
            }
            if (appeared == t.size()) {
                while (appeared_count[s[start]]>excepted_count[s[start]] 
                      || excepted_count[s[start]]==0) {
                    appeared_count[s[start]] --;
                    start ++;
                }
                if (min_width > end-start+1) {
                    min_width = end-start+1;
                    min_start = start;
                }
            }
        }
        return (min_width == INT_MAX) ? "" : s.substr(min_start, min_width);
    }
};