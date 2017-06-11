'''
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
'''


# radix sort
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

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().maximumGap([0,3,9,5,2]), 4)
        self.assertEqual(Solution().maximumGap([0,9,5]), 5)
    def test2(self):
        self.assertEqual(Solution().maximumGap([0, 0x7fffffff]), 0x7fffffff)
    def test3(self):
        self.assertEqual(Solution().maximumGap([12]), 0)
        self.assertEqual(Solution().maximumGap([]), 0)
    def test4(self):
        self.assertEqual(Solution().maximumGap(range(0, 1000000, 10)), 10)

if __name__ == '__main__':
    unittest.main()

