//  Design Compressed String Iterator

class StringIterator {
public:
    StringIterator(const string& compressedString):compressed(), idx(0), cnt(0) {
        int end, freq;
        
        for (int idx = 0; idx < compressedString.size(); idx = end) {
            char ch = compressedString[idx++];
            
            for (end = idx; end<compressedString.size() && isdigit(compressedString[end]); ++end);
            freq = stoi(compressedString.substr(idx, end-idx));
            compressed.push_back(make_pair(ch, freq));
        }
    }
    
    char next() {
        char ch = ' ';
        
        if (hasNext()) {
            ch = compressed[idx].first;
            if (++cnt >= compressed[idx].second) {
                ++idx;
                cnt = 0;
            }
        }
        return ch;
    }
    
    bool hasNext() {
        return idx < compressed.size();
    }
    
private:
    vector<pair<char, int>> compressed;
    int idx, cnt;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
