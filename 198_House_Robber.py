'''
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
'''


class Solution(object):
    def rob(self, nums):
        l = len(nums)
        if l == 0: return 0
        elif l <= 2: return max(nums)
        x, y = nums[0], nums[1]
        for num in nums[2:]:
            x, y = max(x, y), max(x + num, y)
        return y

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().rob([4,2,1,5,3]), 9)
    def test2(self):
        self.assertEqual(Solution().rob([1,2]), 2)
        self.assertEqual(Solution().rob([1]), 1)
        self.assertEqual(Solution().rob([]), 0)

if __name__ == '__main__':
    unittest.main()

