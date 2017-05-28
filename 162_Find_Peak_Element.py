'''
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] != num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = Integer.MIN_VALUE.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
'''


class Solution(object):
    def findPeakElement(self, nums):
        l = len(nums)
        if l == 0: return None
        elif l == 1: return 0
        if nums[0] > nums[1]: return 0
        if nums[-1] > nums[-2]: return l-1
        def binsearch(x, y):
            if x >= y: return x
            m = (x + y) / 2
            if nums[m] > nums[m-1] and nums[m] > nums[m+1]: return m
            if nums[m] < nums[m+1]: return binsearch(m+1, y)
            else: return binsearch(x, m-1)
        return binsearch(0, l-1)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().findPeakElement([1,2,3,1]), 2)
    def test2(self):
        self.assertEqual(Solution().findPeakElement([1,2,3,4,5]), 4)
    def test3(self):
        self.assertEqual(Solution().findPeakElement([5,4,3,2,1]), 0)
    def test4(self):
        self.assertEqual(Solution().findPeakElement([1]), 0)

if __name__ == '__main__':
    unittest.main()

