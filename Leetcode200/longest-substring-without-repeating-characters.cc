//  Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (!s.size()) return 0;
        vector<int> seenMap(128, 0);
        int maxLen = 0;
        int start = 0;
        int end = 0;
        while (start < s.size() && end < s.size()) {
            if (!seenMap[s[end]]) {
                // Move end and add to map
                seenMap[s[end++]] = 1;
                maxLen = max(maxLen, end - start);
            } else {
                seenMap[s[start++]] = 0;
            }
        }
        return maxLen;
    }
};