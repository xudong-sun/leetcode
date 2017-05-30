'''
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.
'''

'''
# count: O(n) time, O(n) space
from collections import defaultdict
class Solution(object):
    def majorityElement(self, nums):
        t = len(nums) / 2 + 1
        count = defaultdict(int)
        for num in nums:
            count[num] += 1
            if count[num] == t: return num
'''

# Moore's voting algorithm
class Solution(object):
    def majorityElement(self, nums):
        ans = count = 0
        for num in nums:
            if count == 0: ans, count = num, 1
            else: count += 1 if num == ans else -1
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().majorityElement([1,2,3,2,2]), 2)
    def test2(self):
        self.assertEqual(Solution().majorityElement([1]), 1)

if __name__ == '__main__':
    unittest.main()

