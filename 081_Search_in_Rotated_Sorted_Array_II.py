'''
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
'''


# worst case: O(n)
class Solution(object):
    def bin_search(self, nums, target, x, y):
        if x > y: return False
        if x == y:
            if nums[x] == target: return True
            else: return False
        if nums[x] == target: return True
        if nums[y] == target: return True
        m = (x + y) / 2
        if nums[m] == target: return True
        if nums[x] < nums[y]:
            if target < nums[m]: return self.bin_search(nums, target, x+1, m-1)
            else: return self.bin_search(nums, target, m+1, y-1)
        elif nums[x] < nums[m] or nums[x] == nums[m] > nums[y]:
            if nums[x] < target < nums[m]: return self.bin_search(nums, target, x+1, m-1)
            else: return self.bin_search(nums, target, m+1, y-1)
        elif nums[m] < nums[y] or nums[m] == nums[y] < nums[x]:
            if nums[m] < target < nums[y]: return self.bin_search(nums, target, m+1, y-1)
            else: return self.bin_search(nums, target, x+1, m-1)
        else: return self.bin_search(nums, target, x+1, y-1)
    def search(self, nums, target):
        return self.bin_search(nums, target, 0, len(nums)-1)

if __name__ == '__main__':
    print Solution().search([2,2,2,2,5,2], 5)
    print Solution().search([], 1)

