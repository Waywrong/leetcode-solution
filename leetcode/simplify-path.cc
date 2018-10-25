//  Simplify Path

class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        stringstream ss(path);
        vector<string> vec;
        while (getline(ss, temp, '/')) {
            if (temp=="." || temp=="")  continue;
            if (temp==".." && !vec.empty()) vec.pop_back();
            else if (temp != "..")  vec.push_back(temp);
        }
        for (auto &s : vec) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};