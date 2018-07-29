//  Palindrome Pairs

//  Time O(NK), Space O(N)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> map;
        for (int i=0; i<words.size(); i++) {
            string t = words[i];
            reverse(t.begin(), t.end());
            map[t] = i;
        }
        if (find(words.begin(), words.end(), "") != words.end()) {
            for (int i=0; i<words.size(); i++) {
                if (words[i] == "") continue;
                if (isPalindrome(words[i])) 
                    res.push_back(vector<int> { map[""], i });
            }
        }
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                string lstr = words[i].substr(0, j);
                string rstr = words[i].substr(j, words[i].size()-j);
                if (map.count(lstr)>0 && map[lstr]!=i && isPalindrome(rstr))
                    res.push_back(vector<int> { i, map[lstr] });
                if (map.count(rstr)>0 && map[rstr]!=i && isPalindrome(lstr))
                    res.push_back(vector<int> { map[rstr], i });
            }
        }
        return res;
    }
    
    bool isPalindrome(string &s) {
        int l = 0, r = s.size()-1;
        while (l < r) 
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};
