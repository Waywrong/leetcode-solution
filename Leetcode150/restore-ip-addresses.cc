//  Restore IP Addresses

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)  return vector<string>();
        vector<string> res;
        vector<string> ip;
        dfs(s, 0, ip, res);
        return res;
    }
    
    void dfs(string &s, int cur, vector<string> &ip, vector<string> &res) {
        if (cur<s.size() && ip.size()>=4)   return;
        if (cur==s.size() && ip.size()==4) {
            string comb = ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3];
            res.push_back(comb);
        }
        for (int i=cur; i<cur+3; i++) {
            if (i >= s.size())  break;
            string temp = s.substr(cur, i-cur+1);
            if (temp.size()>1 && temp[0]=='0')   break;
            if ((unsigned int)(atoi(temp.c_str())) > 255)   break;
            ip.push_back(temp);
            dfs(s, i+1, ip, res);
            ip.pop_back();
        }
    }
};