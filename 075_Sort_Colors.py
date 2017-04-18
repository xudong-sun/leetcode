'''
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
'''


class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """

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

if __name__ == '__main__':
    nums = [2,2,1,0]
    Solution().sortColors(nums)
    print(nums)
