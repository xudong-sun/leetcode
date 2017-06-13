'''
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
'''


class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        l = len(nums)
        if k >= l-1: return len(set(nums)) != len(nums)
        i, j, c = 0, k+1, set(nums[:k+1])
        while len(c) == k+1:
            if j == l: return False
            c.remove(nums[i])
            c.add(nums[j])
            j += 1
            i += 1
        return True

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertFalse(Solution().containsNearbyDuplicate([1,2,3,4,1], 3))
    def test2(self):
        self.assertTrue(Solution().containsNearbyDuplicate([1,2,3,1,4], 3))
    def test3(self):
        self.assertTrue(Solution().containsNearbyDuplicate([1,2,3,4,2], 3))
    def test4(self):
        self.assertFalse(Solution().containsNearbyDuplicate([1,2,3,4], 3))
    def test5(self):
        self.assertFalse(Solution().containsNearbyDuplicate([], 1))
    def test6(self):
        self.assertFalse(Solution().containsNearbyDuplicate([1,1], 0))

if __name__ == '__main__':
    unittest.main()

