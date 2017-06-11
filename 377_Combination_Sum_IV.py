'''
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
'''


class Solution(object):
    def combinationSum4(self, nums, target):
        a = [1] + [0] * target
        for n in xrange(1, target+1):
            for num in nums:
                if num <= n: a[n] += a[n-num]
        return a[-1]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().combinationSum4([1,2,3], 4), 7)
    def test2(self):
        self.assertEqual(Solution().combinationSum4([8], 1), 0)

if __name__ == '__main__':
    unittest.main()

