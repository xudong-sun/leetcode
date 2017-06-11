'''
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
'''

'''
# O(n) space
class Solution(object):
    def rotate(self, nums, k):
        k %= len(nums)
        nums[:] = nums[-k:] + nums[:-k]
'''

# O(1) space: reverse
class Solution(object):
    def rotate(self, nums, k):
        l = len(nums)
        k %= l
        def reverse(x, y):
            i, j = x, y
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        reverse(0, l-1-k)
        reverse(l-k, l-1)
        nums.reverse()

import unittest
class Test(unittest.TestCase):
    def test1(self):
        nums = [1,2,3,4,5,6,7]
        Solution().rotate(nums, 3)
        self.assertEqual(nums, [5,6,7,1,2,3,4])
    def test2(self):
        nums = [1,2,3,4,5,6,7]
        Solution().rotate(nums, 10)
        self.assertEqual(nums, [5,6,7,1,2,3,4])
    def test3(self):
        nums = [1,2,3]
        Solution().rotate(nums, 0)
        self.assertEqual(nums, [1,2,3])
    def test4(self):
        nums = [1,2,3]
        Solution().rotate(nums, 3)
        self.assertEqual(nums, [1,2,3])

if __name__ == '__main__':
    unittest.main()

