'''
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
'''


class Solution(object):
    def jump(self, nums):
        l = len(nums)
        if l < 2: return 0
        res = [l] * l
        res[0] = 0
        i = j = 0
        while True:
            x = i + nums[i]
            if x >= l - 1: return res[i] + 1
            if x > j:
                for k in range(j+1, x+1): res[k] = res[i] + 1
                j = x
            i += 1

if __name__ == '__main__':
    print(Solution().jump([5,1,8,0,0,0,0,1]))

