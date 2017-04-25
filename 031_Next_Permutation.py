'''
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 -> 1,3,2
3,2,1 -> 1,2,3
1,1,5 -> 1,5,1
'''

class Solution(object):
    def nextPermutation(self, nums):
        l = len(nums)
        if l < 2: return
        i = l - 2
        while i >= 0 and nums[i] >= nums[i+1]: i -= 1
        if i < 0:
            for i in xrange(0, (l+1)/2): nums[i], nums[l-1-i] = nums[l-1-i], nums[i]
        else:
            flag = True
            for j in xrange(i+1, (i+l+1)/2):
                if flag and nums[j+1] <= nums[i]:
                    nums[i], nums[j] = nums[j], nums[i]
                    flag = False
                nums[j], nums[i+l-j] = nums[i+l-j], nums[j]
                if flag and nums[j] > nums[i]:
                    nums[i], nums[j] = nums[j], nums[i]
                    flag = False
            if flag:
                nums[i], nums[(i+l)/2] = nums[(i+l)/2], nums[i]

if __name__ == '__main__':
    l = [2,3,3,2,1]
    for _ in xrange(10):
        Solution().nextPermutation(l)
        print l

