//  Max Points on a Line

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        int res = 0;
        for (int i = 0; i < points.size(); i ++) {
            map<pair<int, int>, int> m;
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); j ++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate; 
                    continue;
                } 
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx, dy);
                m[make_pair(dx/d, dy/d)] ++;
            }
            res = max(res, duplicate);
            for (auto &p :m)    res = max(res, p.second + duplicate);
        }
        return res;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};
