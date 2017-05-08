'''
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
'''


class Solution(object):
    def subsets(self, nums):
        res = []
        l = len(nums)
        N = 1 << l
        for i in xrange(N):
            res.append([])
            j = 0
            while i > 0:
                if i & 1 != 0: res[-1].append(nums[j])
                i >>= 1
                j += 1
        return res

if __name__ == '__main__':
    print Solution().subsets([1,2,3,4])


