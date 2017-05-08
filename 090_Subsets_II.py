'''
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
'''


class Solution(object):
    def subsetsWithDup(self, nums):
        m = {}
        for num in nums:
            if num in m: m[num] += 1
            else: m[num] = 2
        total = 1
        for k, v in m.iteritems(): total *= v
        all_result = []
        for i in xrange(total):
            res = []
            for k, v in m.iteritems():
                res += [k] * (i % v)
                i /= v
                if i == 0: break
            all_result.append(res)
        return all_result

if __name__ == '__main__':
    print Solution().subsetsWithDup([])

