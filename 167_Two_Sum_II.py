'''
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
'''


class Solution(object):
    def twoSum(self, numbers, target):
        # bin-search starting point for r
        ll = len(numbers)
        l, r, tt = 0, ll, target - numbers[0]
        while l < r - 1:
            m = (l + r) / 2
            if numbers[m] == tt:
                l = m
                break
            elif numbers[m] < tt: l, r = m, r
            else: l, r = l, m
        # two pointers
        l, r = 0, l
        while l < r:
            while l < r and numbers[l] + numbers[r] > target: r -= 1
            if numbers[l] + numbers[r] == target: return [l+1, r+1]
            l += 1
        assert False

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().twoSum([2,7,11,15], 9), [1,2])
    def test2(self):
        self.assertEqual(Solution().twoSum([-2,-1,0,2], 0), [1,4])
    def test3(self):
        self.assertEqual(Solution().twoSum([-15,-11,-7,-2], -9), [3,4])
    def test4(self):
        self.assertEqual(Solution().twoSum([-0x80000000, 1, 0x7fffffff], -1), [1,3])

if __name__ == '__main__':
    unittest.main()


