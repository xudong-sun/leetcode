'''
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum >= s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
'''

class Solution(object):
    def minSubArrayLen(self, s, nums):
        l = len(nums)
        if l == 0: return 0
        a, i, j = 0, 0, 0
        while j < l:
            a += nums[j]
            if a >= s: break
            j += 1
        if a < s: return 0
        ans = j + 1
        for i in xrange(l):
            a -= nums[i]
            while a < s:
                j += 1
                if j == l: return ans
                a += nums[j]
            ans = min(ans, j-i)
        assert False

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().minSubArrayLen(7, [2,3,1,2,4,3]), 2)
    def test2(self):
        self.assertEqual(Solution().minSubArrayLen(7, [3,2,3,1,1,1,1,4,1]), 3)
    def test3(self):
        self.assertEqual(Solution().minSubArrayLen(100, [1,2,3,4,5]), 0)
    def test4(self):
        self.assertEqual(Solution().minSubArrayLen(1, [3,2,5,3]), 1)
    def test5(self):
        self.assertEqual(Solution().minSubArrayLen(3, []), 0)

if __name__ == '__main__':
    unittest.main()

