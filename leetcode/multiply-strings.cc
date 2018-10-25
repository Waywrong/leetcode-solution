//  Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        int n1 = num1.length(), n2 = num2.length();
        vector<int> products(n1+n2, 0);
        for (int i = n1-1; i >= 0; i --)
            for (int j = n2-1; j >= 0; j --)
                products[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
        int carry = 0;
        for (int i = n1+n2-1; i > 0; i --) {
            int tmp = (products[i] + carry) % 10;
            carry = (products[i] + carry) / 10;
            products[i] = tmp;
        }
        if (carry)  products[0] = carry;
        string res = "";
        for (auto n : products) res += to_string(n);
        if (res[0] == '0')   res.erase(res.begin());
        return res;
    }
};
