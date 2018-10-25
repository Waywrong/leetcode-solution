//  Palindrome Number

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        long n = long(x);
        long temp = 0;
        while (n != 0) {
            temp = temp * 10 + n % 10;
            n /= 10;
        }
        return temp == (long)x;
    }
};