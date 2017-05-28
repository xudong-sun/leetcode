'''
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
'''


class Solution(object):
    def findMin(self, nums):
        def binsearch(x, y):
            if x >= y: return nums[x]
            if x == y - 1: return min(nums[x], nums[y])
            m = (x + y) / 2
            if nums[m] < nums[m-1]: return nums[m]
            if nums[m] < nums[0]: return binsearch(x, m-1)
            else: return binsearch(m+1, y)
        l = len(nums)
        if l == 0: return None
        elif nums[0] <= nums[-1]: return nums[0]
        else: return binsearch(0, l-1)

if __name__ == '__main__':
    print Solution().findMin([4,5,6,7,0,1,2])
    print Solution().findMin([1,2,3,4,5])
    print Solution().findMin([1,2])
    print Solution().findMin([1])
    print Solution().findMin([])

