//  Sqrt(x)

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x/2+1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (x/mid < mid)    high = mid-1;
            else if (x/(mid+1) >= mid+1)    low = mid+1;
            else    return mid;
        }
    }
};
