'''
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
'''

class Solution(object):
    def bin_search_first(self, nums, target, x, y):
        if x > y: return -1
        if x == y:
            if nums[x] == target and nums[x-1] != target: return x
            else: return -1
        m = (x + y) / 2
        if nums[m] < target: return self.bin_search_first(nums, target, m+1, y)
        else: return self.bin_search_first(nums, target, x, m)
    def bin_search_last(self, nums, target, x, y):
        if x == y: return x
        m = (x + y + 1) / 2
        if nums[m] > target: return self.bin_search_last(nums, target, x, m-1)
        else: return self.bin_search_last(nums, target, m, y)
    def searchRange(self, nums, target):
        if len(nums) == 0: return [-1, -1]
        if nums[0] == target: x = 0
        else: x = self.bin_search_first(nums, target, 0, len(nums)-1)
        if x == -1: return [-1, -1]
        if nums[-1] == target: y = len(nums) - 1
        else: y = self.bin_search_last(nums, target, x, len(nums)-1)
        return [x, y]

if __name__ == '__main__':
    print Solution().searchRange([], 5)

