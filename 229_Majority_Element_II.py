'''
Given an integer array of size n, find all elements that appear more than floor(n/3) times. The algorithm should run in linear time and in O(1) space.
'''


# Moore's voting algorithm (revised)
class Solution(object):
    def majorityElement(self, nums):
        ans1, ans2, count1, count2 = 0, 1, 0, 0
        for num in nums:
            if num == ans1: count1 += 2
            elif num == ans2: count2 += 2
            elif count1 <= 0:
                ans1 = num
                count1 += 2
            elif count2 <= 0: 
                ans2 = num
                count2 += 2
            if num != ans1: count1 -= 1
            if num != ans2: count2 -= 1
        t = len(nums) / 3
        return [n for n in (ans1, ans2) if nums.count(n) > t]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertItemsEqual(Solution().majorityElement([1,2,1,2,3]), [1,2])
    def test2(self):
        self.assertItemsEqual(Solution().majorityElement([1,2,3,4,4]), [4])
    def test3(self):
        self.assertItemsEqual(Solution().majorityElement([1,1,1,1]), [1])
        self.assertItemsEqual(Solution().majorityElement([2,2,2,2]), [2])
    def test4(self):
        self.assertItemsEqual(Solution().majorityElement([1]), [1])
    def test5(self):
        self.assertItemsEqual(Solution().majorityElement([0,0,0,0]), [0])
        self.assertItemsEqual(Solution().majorityElement([0,3,0,1,1]), [0,1])
    def test6(self):
        self.assertItemsEqual(Solution().majorityElement([1,1,2,2,3,3]), [])
    def test7(self):
        self.assertItemsEqual(Solution().majorityElement([]), [])

if __name__ == '__main__':
    unittest.main()

