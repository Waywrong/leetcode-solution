//  Employee Free Time

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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> intervals;
        for (auto &x : schedule)
            for (auto &y : x)
                insert_intervals(intervals, y);
        vector<Interval> record = merge_intervals(intervals);
        vector<Interval> res;
        if (record.size() < 2)  return res;
        for (int i=0; i<record.size()-1; i++)
            res.push_back(Interval(record[i].end, record[i+1].start));
        return res;
    }
    
    void insert_intervals(vector<Interval> &intervals, Interval &new_interval) {
        int l = 0, r = intervals.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (intervals[mid].start < new_interval.start)
                l = mid + 1;
            else    r = mid;
        }
        intervals.insert(intervals.begin()+l, new_interval);
    }
    
    vector<Interval> merge_intervals(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.size() == 0)  return res;
        int start = intervals[0].start, end = intervals[0].end;
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i].start > end) {
                res.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else
                end = (intervals[i].end > end) ? intervals[i].end : end;
        }
        res.push_back(Interval(start, end));
        return res;
    }
};