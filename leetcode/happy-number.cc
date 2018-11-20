//  Happy Number

class Solution {
public:
    bool isHappy(int n) {
        int x = cal(n), y = cal(x);
        while (x != y) {
            x = cal(x);
            y = cal(cal(y));
        }
        return (x == 1);
    }
    
    int cal(int n) {
        int t, res = 0;
        while (n != 0) {
            t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }
};