//  Word Ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        int res = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size(), k = 0;
            while (k++ < n) {
                string tmp = q.front(); q.pop();
                for (int i = 0; i < tmp.length(); i ++) {
                    char ch = tmp[i];
                    for (char c = 'a'; c <= 'z'; c ++) {
                        if (c == ch)    continue;
                        tmp[i] = c;
                        if (wordSet.find(tmp) != wordSet.end()) {
                            if (tmp == endWord) return ++res;
                            q.push(tmp);
                            wordSet.erase(tmp);
                        }
                    }
                    tmp[i] = ch;
                }
            }
            res ++;
        }
        return 0;
    }
};
