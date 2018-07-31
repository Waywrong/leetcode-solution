//  Insert Interval

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), comp);
        insert_intervals(intervals, newInterval);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start > end) {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else
                end = (intervals[i].end>end) ? intervals[i].end : end;
        }
        res.push_back(Interval(start, end));
        return res;
    }
    
private:
    static bool comp(Interval i, Interval j) {
        return i.start < j.start;
    }
    
    void insert_intervals(vector<Interval> &intervals, Interval newInterval) {
        int i = 0, j = intervals.size();
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (intervals[mid].start < newInterval.start)   i = mid + 1;
            else    j = mid;
        }
        intervals.insert(intervals.begin()+i, newInterval);
    }
};