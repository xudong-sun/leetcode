'''
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
'''


class Solution(object):
    def rob(self, nums):
        l = len(nums)
        l = len(nums)
        if l == 0: return 0
        elif l <= 2: return max(nums)
        # case 1: rob [:-1]
        x, y = nums[0], max(nums[0], nums[1])
        for num in nums[2:-1]:
            x, y = y, max(x + num, y)
        ans = y
        # case 2: rob [1:]
        x, y = 0, nums[1]
        for num in nums[2:]:
            x, y = max(x, y), max(x + num, y)
        return max(ans, y)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().rob([4,2,1,5,3]), 9)
    def test2(self):
        self.assertEqual(Solution().rob([1,2]), 2)
        self.assertEqual(Solution().rob([1]), 1)
        self.assertEqual(Solution().rob([]), 0)
    def test3(self):
        self.assertEqual(Solution().rob([4,2,1,5]), 7)
    def test4(self):
        self.assertEqual(Solution().rob([4,1,2]), 4)

if __name__ == '__main__':
    unittest.main()

