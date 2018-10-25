//  Pow(x,n)

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        double t = myPow(x, n/2);
        double res;
        if (n % 2)
            res = t * t * x;
        else
            res = t * t;
        return !isinf(res) ? res : 0;
    }
};