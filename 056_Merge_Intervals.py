'''
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
'''


from structs.interval import Interval, generate_intervals

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

if __name__ == '__main__':
    intervals = generate_intervals([])
    merged = Solution().merge(intervals)
    print ', '.join([str(i) for i in merged])

