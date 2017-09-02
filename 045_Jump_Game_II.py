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

'''
# Solution 1: straightforward dp, O(nk), 86ms
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
                for k in xrange(j+1, x+1): res[k] = res[i] + 1
                j = x
            i += 1
'''

# Solution 2: O(n), 49ms
# Note that values in `res` is non-decreasing
# `i` is the current index
# `step` is the current #steps
# `reach` is the farthest with `step` steps
# `next_reach` is the farthest with `step+1` steps
class Solution(object):
    def jump(self, nums):
        step, reach, next_reach, l = 0, 0, 0, len(nums) - 1
        if l < 1: return 0
        for i, num in enumerate(nums):
            if i > reach:
                step += 1
                reach = next_reach
            if i + num > next_reach:
                next_reach = i + num
                if next_reach >= l: return step + 1
        return step

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().jump([2,3,1,1,4]), 2)
    def test2(self):
        self.assertEqual(Solution().jump([5,1,8,0,0,0,0,1]), 2)
    def test3(self):
        self.assertEqual(Solution().jump([1]*100), 99)
    def test4(self):
        self.assertEqual(Solution().jump([1]), 0)
    def test5(self):
        self.assertEqual(Solution().jump([]), 0)

if __name__ == '__main__':
    unittest.main()
