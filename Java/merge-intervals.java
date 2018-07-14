//  Merge Intervals

/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

// Time O(nlogn), Space O(1)
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> ans = new ArrayList<Interval>();
        int size = intervals.size();
        if (size == 0)
            return ans;
        quicksort(intervals, 0, size-1);
        int i = 1, start = intervals.get(0).start, end = intervals.get(0).end;
        while (i < size) {
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
    
    private void quicksort(List<Interval> intervals, int start, int end) {
        if (start >= end)
            return;
        Interval k = intervals.get(start);
        int i = start, j = end;
        while (i < j) {
            while (i<j && intervals.get(j).start>=k.start)
                j --;
            if (i < j)
                intervals.set(i++, intervals.get(j));
            while (i<j && intervals.get(i).start<=k.start)
                i ++;
            if (i < j)
                intervals.set(j--, intervals.get(i));
        }
        intervals.set(i, k);
        quicksort(intervals, start, i-1);
        quicksort(intervals, i+1, end);
    }
}