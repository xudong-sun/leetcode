'''
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
'''


class Solution(object):
    def findMin(self, nums):
        def binsearch(x, y):
            if x >= y: return nums[x]
            elif x == y - 1: return min(nums[x], nums[y])
            if nums[x] < nums[y]: return nums[x]
            m = (x + y) / 2
            if nums[m] < nums[m-1]: return nums[m]
            if nums[x] > nums[y]:
                if nums[m] < nums[x]: return binsearch(x, m-1)
                else: return binsearch(m+1, y)
            else: # nums[x] == nums[y]
                if nums[m] < nums[x]: return binsearch(x, m-1)
                elif nums[m] > nums[x]: return binsearch(m+1, y)
                else: return min(binsearch(x, m-1), binsearch(m+1, y))
        l = len(nums)
        if l == 0: return None
        return binsearch(0, l-1)

if __name__ == '__main__':
    print Solution().findMin([4,5,6,7,0,1,2])
    print Solution().findMin([4,5])
    print Solution().findMin([1])
    print Solution().findMin([])
    print Solution().findMin([2,2,2,2,2,2,2,2])
    print Solution().findMin([2,2,1,2,2,2,2,2])
    print Solution().findMin([2,2,2,2,2,2,2,1])
    print Solution().findMin([2,2,3,2,2,2,2,2])

