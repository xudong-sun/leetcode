'''
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
'''


from structs.interval import Interval, generate_intervals

'''
# Solution 1: mark ( as 1 and ) as -1
# 109ms
class Solution(object):
    def merge(self, intervals):
        a = []
        res = []
        for interval in intervals:
            a.append((interval.start, -1))
            a.append((interval.end, 1))
        a.sort()
        z = 0
        for j, q in a:
            z += q
            if z == 0: res.append(Interval(s, j))
            elif z == -1 and q == -1: s = j
        return res
'''

# Solution 2, 86ms
class Solution(object):
    def merge(self, intervals):
        if len(intervals) == 0: return []
        res = []
        intervals.sort(key=lambda x: x.start)
        start, end = intervals[0].start, intervals[0].end
        for interval in intervals:
            if interval.start > end:
                res.append(Interval(start, end))
                start, end = interval.start, interval.end
            else:
                end = max(end, interval.end)
        res.append(Interval(start, end))
        return res

import unittest
class Test(unittest.TestCase):
    def to_string(self, intervals):
        return ', '.join([str(i) for i in intervals])
    def test1(self):
        res = self.to_string(Solution().merge(generate_intervals([[1,3],[2,6],[8,10],[15,18]])))
        ans = self.to_string(generate_intervals([[1,6],[8,10],[15,18]]))
        self.assertEqual(res, ans)
    def test2(self):
        res = self.to_string(Solution().merge(generate_intervals([[7,8],[1,3],[3,6],[4,6]])))
        ans = self.to_string(generate_intervals([[1,6],[7,8]]))
        self.assertEqual(res, ans)
    def test3(self):
        self.assertListEqual(Solution().merge([]), [])

if __name__ == '__main__':
    unittest.main()
