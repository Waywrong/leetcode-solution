//  Word Ladder II

class Solution {
private:
    string _beginWord;
    string _endWord;

    int _len = 0;
    int _loop_cnt = 0;
    int _effect_cnt = 0;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return ret;
        }

        _beginWord  = beginWord;
        _endWord    = endWord;
        _len        = beginWord.length();

        queue<string> WordQueue[2];
        WordQueue[0].push(beginWord);
        WordQueue[1].push(endWord);

        unordered_set<string> WordSets[2];
        for (auto && word : wordList) {
            WordSets[0].insert(word);
            WordSets[1].insert(word);
        }
        WordSets[0].erase(beginWord);
        WordSets[1].erase(endWord);

        unordered_set<string> Repeat[2];
        unordered_set<string> SameWord;

        unordered_map<string, vector<string>> Graph[2];

        bool find = false;
        while (!find) {
            for (int i = 0; i < 2; i++) {
                auto setPtr     = &WordSets[i];
                auto repeatPtr  = &Repeat[i];
                auto queuePtr   = &WordQueue[i];
                auto graphPtr   = &Graph[i];

                repeatPtr->clear();

                if (queuePtr->empty()) {
                    find = true;
                    break;
                }

                while (!queuePtr->empty()) {
                    auto root = queuePtr->front();
                    queuePtr->pop();
                    
                    for (auto && word : *setPtr) {
                        _loop_cnt++;
                        if (!diffOnlyOne(root, word)) {
                            continue;
                        }

                        _effect_cnt++;
                        auto it = graphPtr->find(word);
                        if (it == graphPtr->end()) {
                            graphPtr->insert({word, {root}});
                        } else {
                            it->second.push_back(root);
                        }

                        repeatPtr->insert(word);
                        if (word == _beginWord || word == _endWord) {
                            SameWord.insert(word);
                            find = true;
                            break;
                        }
                    }

                    if (find) {
                        break;
                    }
                }
                
                unordered_set<string> * minPtr = nullptr;
                unordered_set<string> * maxPtr = nullptr;
                if (Repeat[0].size() > Repeat[1].size()) {
                    minPtr = &Repeat[1];
                    maxPtr = &Repeat[0];
                } else {
                    minPtr = &Repeat[0];
                    maxPtr = &Repeat[1];
                }

                for (auto && w : *minPtr) {
                    if (maxPtr->find(w) != maxPtr->end()) {
                        SameWord.insert(w);
                        find = true;
                    }
                }

                if (find)
                    break;
                
                for (auto && word : *repeatPtr) {
                    queuePtr->push(word);
                    setPtr->erase(word);
                }
            }

            if (find)
                break;
        }

        vector<vector<string>> Path[2];
        for (auto && word : SameWord) {
            findPath(Graph[0], word, Path[0], {});
            findPath(Graph[1], word, Path[1], {});
        }

        for (auto pl : Path[0]) {
            for (auto pr : Path[1]) {
                if (pl.front() != pr.front()) {
                    continue;
                }

                auto p = pl;
                std::reverse(p.begin(), p.end());
                p.pop_back();
                p.insert(p.end(), pr.begin(), pr.end());
                ret.push_back(std::move(p));
            }
        }

        return ret;
    }

    void findPath(
            const unordered_map<string, vector<string>>& graph,
            const string& key,
            vector<vector<string>>& path,
            vector<string> subpath
            ) {
        auto it = graph.find(key);
        if (it == graph.end()) {
            subpath.push_back(key);
            path.push_back(std::move(subpath));
            return;
        }

        for (const auto & word : it->second) {
            subpath.push_back(key);
            findPath(graph, word, path, subpath);
            subpath.pop_back();
        }
    }

    inline bool diffOnlyOne(const string& p, const string& q) {
        int count = 0;
        int i = 0;
        while (i < _len) {
            if (p[i] != q[i]) {
                ++count;
            }
            i++;
        }
        
        return count == 1;
    }

    int get_cnt() {
        return _loop_cnt;
    }

    int get_effect_cnt() {
        return _effect_cnt;
    }
};
