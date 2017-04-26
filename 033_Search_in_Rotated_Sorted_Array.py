'''
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
'''

class Solution(object):
    def bin_search(self, nums, target, x, y):
        if x > y: return -1
        if x == y:
            if nums[x] == target: return x
            else: return -1
        if nums[x] == target: return x
        if nums[y] == target: return y
        m = (x + y) / 2
        if nums[m] == target: return m
        if nums[x] < nums[y]:
            if target < nums[m]: return self.bin_search(nums, target, x+1, m-1)
            else: return self.bin_search(nums, target, m+1, y-1)
        elif nums[y] < nums[x] < nums[m]:
            if nums[x] < target < nums[m]: return self.bin_search(nums, target, x+1, m-1)
            else: return self.bin_search(nums, target, m+1, y-1)
        else:
            if nums[m] < target < nums[y]: return self.bin_search(nums, target, m+1, y-1)
            else: return self.bin_search(nums, target, x+1, m-1)
    def search(self, nums, target):
        return self.bin_search(nums, target, 0, len(nums)-1)

if __name__ == '__main__':
    print Solution().search([1], 0)

