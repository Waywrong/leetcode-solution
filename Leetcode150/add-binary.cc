//  Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int p1 = a.length()-1, p2 = b.length()-1;
        int carry = 0;
        while (p1>=0 || p2>=0) {
            int sum = (p1>=0 ? a[p1]-'0' : 0) + (p2>=0 ? b[p2]-'0' : 0) + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
            p1 --;
            p2 --;
        }
        if (carry) 
            res = "1" + res;
        return res;
    }
};