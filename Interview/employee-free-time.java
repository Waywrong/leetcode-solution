//  Employee Free Time

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
 
// Time O(N), Space O(N)
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> record = new ArrayList<Interval>();
        for (int i=0; i<schedule.size(); i++)
            for (int j=0; j<schedule.get(i).size(); j++)
                insertInterval(record, schedule.get(i).get(j));
        List<Interval> intervals = mergeIntervals(record);
        List<Interval> res = searchFreeTimes(intervals);
        return res;
    }
    
    private void insertInterval(List<Interval> record, Interval x) {
        int l = 0, r = record.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (record.get(mid).start < x.start)
                l = mid + 1;
            else
                r = mid;
        }
        record.add(l, x);
    }
    
    private List<Interval> mergeIntervals(List<Interval> record) {
        List<Interval> res = new ArrayList<Interval>();
        if (record.size() == 0) return res;
        int start = record.get(0).start, end = record.get(0).end;
        for (int i=1; i<record.size(); i++) {
            if (record.get(i).start > end) {
                res.add(new Interval(start, end));
                start = record.get(i).start;
                end = record.get(i).end;
            }
            else
                end = (record.get(i).end>end) ? record.get(i).end : end;
        }
        res.add(new Interval(start, end));
        return res;
    }
    
    private List<Interval> searchFreeTimes(List<Interval> record) {
        List<Interval> res = new ArrayList<Interval>();
        if (record.size() <= 1) return res;
        int i=1;
        while (i < record.size()) { 
            res.add(new Interval(record.get(i-1).end, record.get(i).start));
            i ++;
        }
        return res;
    }
}
