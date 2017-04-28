'''
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
'''


class Solution(object):
    def canJump(self, nums):
        l = len(nums)
        if l < 2: return True
        i = j = 0
        while True:
            x = i + nums[i]
            if x >= l - 1: return True
            if x > j: j = x
            i += 1
            if i > j: return False

if __name__ == '__main__':
    print(Solution().canJump([1]))

