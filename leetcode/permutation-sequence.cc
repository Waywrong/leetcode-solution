//  Permutation Sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        for (int i=1; i<=n; i++)    res += to_string(i);
        for (int i=1; i<k; i++)
            get_next_permutation(res);
        return res;
    }
    
    void get_next_permutation(string &s) {
        int i, j, k;
        for (i=s.size()-1; i>0; i--) {
            j = i - 1;
            if (s[j] >= s[i])   continue;
            for (k=s.size()-1; k>=i; k--)
                if (s[k] > s[j])
                    break;
            swap(s[k], s[j]);
            reverse(s.begin()+i, s.end());
            return;
        }
        reverse(s.begin(), s.end());
    }
};