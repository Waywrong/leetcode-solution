//  Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)  return 0;
        if (divisor == 0)   return INT_MAX;
        double x = log(fabs(dividend));
        double y = log(fabs(divisor));
        double res = exp(x-y);
        res = (long)res;
        if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            return (-res < INT_MIN) ? INT_MIN : -res;
        else    return (res > INT_MAX) ? INT_MAX : res;
    }
};