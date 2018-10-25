//  Plus One

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int t = digits[digits.size()-1] + 1;
        int carry = t / 10;
        res.insert(res.begin(), t % 10);
        for (int i=digits.size()-2; i>=0; i--) {
            t = digits[i] + carry;
            carry = t / 10;
            res.insert(res.begin(), t % 10);
        }
        if (carry)  res.insert(res.begin(), 1);
        return res;
    }
};