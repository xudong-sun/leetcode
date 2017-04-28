'''
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
'''

# a special kind of sort: you know where to put each element beforehand
# here we know: value i should be placed at i-1
# O(n)
class Solution(object):
    def firstMissingPositive(self, nums):
        l = len(nums)
        if l == 0: return 1
        # sort
        for i in xrange(l):
            v = nums[i]
            while v > 0 and v <= l and v != nums[v - 1]:
                nums[i], nums[v-1] = nums[v-1], nums[i]
                v = nums[i]
        # find first missing positive
        for i in xrange(l):
            if nums[i] != i+1: break
        if nums[i] == i+1: return i+2
        else: return i+1

if __name__ == '__main__':
    print Solution().firstMissingPositive([])

