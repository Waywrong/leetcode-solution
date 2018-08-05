//  Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())  return 0;
        string store = "";
        int max_len = 0;
        for (int i=0; i < s.size(); i ++) {
            int pos = store.find(s[i]);
            if (pos != -1)  store = store.substr(pos + 1);
            store += s[i];
            max_len = max(max_len, (int)store.size());
        }
        return max_len;
    }
};