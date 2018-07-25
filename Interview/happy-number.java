//  Happy Number

// Time O(N), Space O(1)
class Solution {
    public boolean isHappy(int n) {
        int x = cal(n), y = cal(cal(n));
        while (x != y) {
            if (x==1 || y==1)   return true;
            x = cal(x);
            y = cal(cal(y));
        }
        return x==1;
    }
    
    private int cal(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
}