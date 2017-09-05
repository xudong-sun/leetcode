'''
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
'''


# Solution 1: radix sort, O(n), 162ms
class Solution(object):
    def maximumGap(self, nums):
        buckets = [[], []]
        for d in xrange(31):
            z = 1 << d
            for num in nums:
                buckets[num & z > 0].append(num)
            nums = buckets[0] + buckets[1]
            buckets = [[], []]
        l = len(nums)
        ans = 0
        for i in xrange(l-1): ans = max(ans, nums[i+1] - nums[i])
        return ans

# Solution 2: bucket sort, O(n), 46ms
# with n numbers, the maximum gap must be larger than ceil((max - min) / n)
# so if we divide the range into `n` bins, the maximum gap should be values across adjacent (different) bins
class Solution(object):
    def maximumGap(self, nums):
        n = len(nums)
        if n < 2: return 0
        nums_min, nums_max = min(nums), max(nums)
        if nums_min == nums_max: return 0
        gap = max((nums_max - nums_min) / n, 1)
        num_bins = (nums_max - nums_min) / gap + 1
        mins, maxs, flags = [0x7fffffff] * num_bins, [0] * num_bins, [False] * num_bins
        for num in nums:
            idx = (num - nums_min) / gap
            flags[idx] = True
            mins[idx] = min(mins[idx], num)
            maxs[idx] = max(maxs[idx], num)
        ans, x = gap, maxs[0]
        for idx in xrange(1, num_bins):
            if flags[idx]:
                ans, x = max(ans, mins[idx] - x), maxs[idx]
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().maximumGap([0,3,9,5,2]), 4)
        self.assertEqual(Solution().maximumGap([0,9,5]), 5)
    def test2(self):
        self.assertEqual(Solution().maximumGap([4,2,5,22,1,3,9,24,0]), 13)
    def test3(self):
        self.assertEqual(Solution().maximumGap([0, 0x7fffffff]), 0x7fffffff)
    def test4(self):
        self.assertEqual(Solution().maximumGap([12]), 0)
        self.assertEqual(Solution().maximumGap([]), 0)
    def test5(self):
        self.assertEqual(Solution().maximumGap(range(0, 1000000, 10)), 10)
    def test6(self):
        self.assertEqual(Solution().maximumGap([1,1,1,1]), 0)
    def test7(self):
        self.assertEqual(Solution().maximumGap([1,1,1,2,1]), 1)

if __name__ == '__main__':
    unittest.main()

