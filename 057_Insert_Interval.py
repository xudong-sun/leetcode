'''
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
'''


from structs.interval import Interval, generate_intervals

class Solution(object):
    def insert(self, intervals, newInterval):
        def _binsearch(intervals, l, r, val):
            if l + 1 >= r: return l
            m = l + (r-l) / 2
            if intervals[m].start == val: return m
            elif intervals[m].start < val: return _binsearch(intervals, m, r, val)
            else: return _binsearch(intervals, l, m, val)
        def find(intervals, val):
            if val < intervals[0].start: return -1
            else: return _binsearch(intervals, 0, len(intervals), val)
        l = len(intervals)
        if l == 0: return [newInterval]
        x1, x2 = find(intervals, newInterval.start), find(intervals, newInterval.end)
        res = []
        if x1 >= 0:
            for interval in intervals[:x1]: res.append(interval)
        if x1 >= 0 and intervals[x1].end >= newInterval.start:
            if intervals[x2].end >= newInterval.end: res.append(Interval(intervals[x1].start, intervals[x2].end))
            else: res.append(Interval(intervals[x1].start, newInterval.end))
        else:
            if x1 >= 0: res.append(intervals[x1])
            if x2 >= 0 and intervals[x2].end >= newInterval.end: res.append(Interval(newInterval.start, intervals[x2].end))
            else: res.append(newInterval)
        for interval in intervals[x2+1:]:
            res.append(interval)
        return res

if __name__ == '__main__':
    intervals = generate_intervals([[1,3]])
    newInterval = Interval(-1, 2)
    inserted = Solution().insert(intervals, newInterval)
    print ', '.join([str(interval) for interval in inserted])


