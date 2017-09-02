'''
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
'''

# Solution 1: one-pass const-space 52ms
# This algorithm works for any number of colors
class Solution(object):
    def sortColors(self, nums):
        i = j = k = 0
        for num in nums:
            if num == 0:
                nums[k] = 2
                nums[j] = 1
                nums[i] = 0
                k += 1
                j += 1
                i += 1
            elif num == 1:
                nums[k] = 2
                nums[j] = 1
                k += 1
                j += 1
            else:
                nums[k] = 2
                k += 1

# Solution 2: one-pass const-space 36ms
# Only works for 3 colors. Idea comes from 041_First_Missing_Positive (sort with known target index)
# Here we just put 0's to the front, and put 2's to the back
# We keep two pointers x,y, pointing to the "next position to put 0(2)"
class Solution(object):
    def sortColors(self, nums):
        x, l = 0, len(nums)
        while x < l and nums[x] == 0: x += 1
        y = l - 1
        while y > x and nums[y] == 2: y -= 1
        i = x
        while i <= y:
            while nums[i] != 1 and i <= y:
                if nums[i] == 0:
                    if i > x: nums[i], nums[x] = nums[x], nums[i]
                    x += 1
                    break
                else:
                    nums[i], nums[y] = nums[y], nums[i]
                    y -= 1
            i += 1

import unittest
class Test(unittest.TestCase):
    def countSort(self, nums):
        c = [0, 0, 0]
        for num in nums: c[num] += 1
        return [0] * c[0] + [1] * c[1] + [2] * c[2]
    def test1(self):
        import random
        for _ in xrange(10):
            nums = [random.randint(0, 2) for _ in xrange(100)]
            ans = self.countSort(nums)
            Solution().sortColors(nums)
            self.assertEqual(nums, ans)
    def test2(self):
        nums = [2,2,0,2,0]
        Solution().sortColors(nums)
        self.assertEqual(nums, [0,0,2,2,2])
    def test3(self):
        nums = [0] * 5
        Solution().sortColors(nums)
        self.assertEqual(nums, [0] * 5)
    def test4(self):
        nums = []
        Solution().sortColors(nums)
        self.assertEqual(nums, [])

if __name__ == '__main__':
    unittest.main()
