//  Count and Say

class Solution {
public:
    string countAndSay(int n) {
        string t = "1";
        for (int i=1; i<n; i++) 
            t = create_str(t);
        return t;
    }
    
    string create_str(string &s) {
        string res = "";
        int start = 0, i = 0;
        for (i=0; i<s.size(); i++) {
            if (s[i] != s[start]) {
                res += to_string(i-start);
                res += s[start];
                start = i --;
            }
        }
        res += to_string(i-start);
        res += s[start];
        return res;
    }
};
