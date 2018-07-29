//  Happy Number

// Time O(N), Space O(1)
class Solution {
public:
    bool isHappy(int n) {
        int x = cal(n), y = cal(cal(n));
        while (x != y) {
            if (x==1 || y==1)   return true;
            x = cal(x);
            y = cal(cal(y));
        }
        return x==1;
    }
    
    int cal(int n) {
        int res = 0;
        while (n != 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};