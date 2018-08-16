//  Substring with Concatenation of All Words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || words[0].empty() || words[0].length()>s.length())
            return res;
        int size = words[0].length();
        int n = words.size();
        unordered_map<string, int> map;
        for (auto &w : words)   map[w] ++;
        for (int i = 0; i+size*n<=s.length(); i ++) {
            if (map.count(s.substr(i, size)) > 0) {
                unordered_map<string, int> cur_map;
                for (int j = 0; j < n; j ++) {
                    string word = s.substr(i+j*size, size);
                    cur_map[word] ++;
                }
                if (cur_map == map) res.push_back(i);
            }            
        }
        return res;
    }
};
