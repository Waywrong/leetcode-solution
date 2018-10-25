//  ZigZag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.size())    return s;
        if (numRows == 1)   return s;
        int group_size = 2 * numRows - 2;
        int group = s.size() / group_size + 1;
        string res = "";
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<group; j++) {
                if (j*group_size+i < s.size())
                    res += s[j*group_size+i];
                if ((j+1)*group_size-i < s.size() && i!=0 && i!=numRows-1)
                    res += s[(j+1)*group_size-i];
            }
        }
        return res;
    }
};