//  Insert Interval

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

// Time O(N), Space O(1)
class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> ans = new ArrayList<Interval>();
        int size = intervals.size(), i = 0;
        for (; i<size && intervals.get(i).start<newInterval.start; i++);
        intervals.add(i, newInterval);
        i = 1;
        int start = intervals.get(0).start, end = intervals.get(0).end;
        while (i < size+1) {
            if (intervals.get(i).start > end) {
                ans.add(new Interval(start, end));
                start = intervals.get(i).start;
                end = intervals.get(i).end;
            }
            if (intervals.get(i).end > end)
                end = intervals.get(i).end;
            i ++;
        }
        ans.add(new Interval(start, end));
        return ans;
    }
}