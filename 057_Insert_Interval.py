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
        res, idx, li = [], 0, len(intervals)
        # phase 1
        while idx < li and intervals[idx].end < newInterval.start: 
            res.append(intervals[idx])
            idx += 1
        # phase 2
        if idx < li: st = min(intervals[idx].start, newInterval.start)
        else: st = newInterval.start
        while idx < li and intervals[idx].start <= newInterval.end: idx += 1
        if idx > 0: en = max(intervals[idx-1].end, newInterval.end)
        else: en = newInterval.end
        res.append(Interval(st, en))
        # phase 3
        while idx < li:
            res.append(intervals[idx])
            idx += 1
        return res

import unittest
class Test(unittest.TestCase):
    def test1(self):
        intervals = generate_intervals([[1,3],[6,9]])
        newInterval = Interval(2, 5)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[1, 5], [6, 9]')
    def test2(self):
        intervals = generate_intervals([[1,2],[3,5],[6,7],[8,10],[12,16]])
        newInterval = Interval(4, 9)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[1, 2], [3, 10], [12, 16]')
    def test3(self):
        intervals = generate_intervals([[1,3]])
        newInterval = Interval(-1, 1)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[-1, 3]')
    def test4(self):
        intervals = generate_intervals([[1,3]])
        newInterval = Interval(-1, 0)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[-1, 0], [1, 3]')
    def test5(self):
        intervals = generate_intervals([[1,3]])
        newInterval = Interval(-1, 4)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[-1, 4]')
    def test6(self):
        intervals = generate_intervals([[1,3]])
        newInterval = Interval(3, 8)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[1, 8]')
    def test7(self):
        intervals = generate_intervals([[1,3]])
        newInterval = Interval(4, 8)
        inserted = Solution().insert(intervals, newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[1, 3], [4, 8]')
    def test8(self):
        newInterval = Interval(4, 8)
        inserted = Solution().insert([], newInterval)
        result_str = ', '.join(map(str, inserted))
        self.assertEqual(result_str, '[4, 8]')


if __name__ == '__main__':
    unittest.main()


