//  Container with Most Water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, h;
        int left = 0, right = height.size()-1;
        while (left < right) {
            h = min(height[left], height[right]);
            max_area = max(max_area, (right-left)*h);
            if (height[left] < height[right])   left ++;
            else    right --;
        }
        return max_area;
    }
};
