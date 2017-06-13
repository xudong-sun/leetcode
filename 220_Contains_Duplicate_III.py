'''
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
'''


# point update, range query: binary search tree, buckets, segment tree (not viable here)
# Solution 1: use buckets, bucket size = t+1
# Solution 2: use BST, this is easily realized with std::set (c++) or TreeSet (java)

class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if t < 0: return False
        MIN = -0x80000000
        bucket = lambda x: (x - MIN) / (t + 1)
        c = {} # buckets
        for idx, num in enumerate(nums):
            key = bucket(num)
            if key in c: return True
            v = c.get(key+1)
            if v is not None and v - num <= t: return True
            v = c.get(key-1)
            if v is not None and num - v <= t: return True
            c[key] = num
            if idx >= k: del c[bucket(nums[idx-k])]
        return False

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertFalse(Solution().containsNearbyAlmostDuplicate([1,2,3,4,1], 3, 0))
    def test2(self):
        self.assertFalse(Solution().containsNearbyAlmostDuplicate([1,4,7,10,2], 3, 1))
    def test3(self):
        self.assertTrue(Solution().containsNearbyAlmostDuplicate([1,9,4,7,10], 3, 1))
    def test4(self):
        self.assertTrue(Solution().containsNearbyAlmostDuplicate([1,1], 1, 0))
    def test5(self):
        self.assertFalse(Solution().containsNearbyAlmostDuplicate([], 1, 1))
    def test6(self):
        self.assertFalse(Solution().containsNearbyAlmostDuplicate([1,1], 0, 1))

if __name__ == '__main__':
    unittest.main()

