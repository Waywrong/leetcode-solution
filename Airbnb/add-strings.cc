//  Add Strings

// Time O(M+N), Space O(N)
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int p1 = num1.size()-1, p2 = num2.size()-1;
        int carry = 0;
        while (p1>=0 || p2>=0) {
            int sum = (p1>=0 ? num1[p1]-'0' : 0) + (p2>=0 ? num2[p2]-'0' : 0) + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
            p1 --;
            p2 --;
        }
        if (carry != 0)
            res = to_string(carry) + res;
        return res;
    }
};