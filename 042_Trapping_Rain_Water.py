'''
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
'''

'''
# Solution 1: O(n), 79ms
# pass 1: calc h[i], which is max{height[i] .. height[-1]}
# pass 2: scan i from left to right, water level should be min{max{height[0] .. height[i]}, h[i]}
class Solution(object):
    def trap(self, height):
        l = len(height)
        if l == 0: return 0
        h = [0] * l
        h[-1] = height[-1]
        for i in xrange(l-2, -1, -1):
            h[i] = max(h[i+1], height[i])
        m = height[0]
        s = 0
        for i in xrange(1, l):
            x = min(m, h[i])
            if height[i] < x: s += x - height[i]
            if height[i] > m: m = height[i]
        return s
'''

# Solution 2: O(n), 49ms
# use a stack. Very similar to 084_Largest_Rectangle_in_Histogram
# add the total area by horizontal slice
class Solution(object):
    def trap(self, height):
        stack, ans = [], 0
        for pos, h in enumerate(height):
            hh_prev = 0
            while len(stack) > 0 and height[stack[-1]] <= h:
                p = stack.pop()
                hh = height[p]
                ans += (hh - hh_prev) * (pos - p - 1)
                hh_prev = hh
            if len(stack) > 0: ans += (h - hh_prev) * (pos - stack[-1] - 1)
            stack.append(pos)
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]), 6)
    def test2(self):
        self.assertEqual(Solution().trap([1,2,2,1]), 0)
    def test3(self):
        self.assertEqual(Solution().trap([1,2,1,1,9,3,1,5]), 8)
    def test4(self):
        self.assertEqual(Solution().trap([5,3,3,1,1,2,2,1,1,3]), 10)
    def test5(self):
        self.assertEqual(Solution().trap([2,2]), 0)
    def test6(self):
        self.assertEqual(Solution().trap([1]), 0)
        self.assertEqual(Solution().trap([]), 0)

if __name__ == '__main__':
    print unittest.main()

