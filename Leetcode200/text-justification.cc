//  Text Justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0, j = 0;
        while (i < n) {
            int len = -1;
            while (j<n && words[j].size()+1+len<=maxWidth) {
                len += 1 + words[j].size();
                j ++;
            }
            int num_space = maxWidth-len+j-i-1;
            int k = i;
            while (num_space) {
                words[k++] += " ";
                num_space --;
                if(j != words.size() && (k == j - 1 || k == j)) k = i;
                if(j == words.size() && k == j) k = j - 1;
            }
            string line = "";
            for (int l=i; l<j; l++)
                line += words[l];
            res.push_back(line);
            i = j;
        }
        return res;
    }
};