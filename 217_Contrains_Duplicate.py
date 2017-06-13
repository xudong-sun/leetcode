'''
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
'''

class Solution(object):
    def containsDuplicate(self, nums):
        return len(set(nums)) != len(nums)

import unittest
class TestCase(unittest.TestCase):
    def test1(self):
        self.assertFalse(Solution().containsDuplicate([1,2,3,4]))
    def test2(self):
        self.assertTrue(Solution().containsDuplicate([1,1]))
    def test3(self):
        self.assertFalse(Solution().containsDuplicate([]))

if __name__ == '__main__':
    unittest.main()

