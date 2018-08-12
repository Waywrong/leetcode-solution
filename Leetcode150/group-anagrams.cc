//  Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for (auto &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        for (auto &x : map)
            res.push_back(x.second);
        return res;
    }
};
