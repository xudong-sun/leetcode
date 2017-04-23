'''
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
'''

class Solution(object):
    def fourSum(self, nums, target):
        nums.sort()
        res = []
        l = len(nums)
        i = 0
        while i < l - 3:
            if nums[i] * 4 > target: break
            j = i + 1
            while j < l - 2:
                if nums[i] + nums[j] * 3 > target: break
                k, m = j + 1, l - 1
                sij = nums[i] + nums[j]
                while k < m:
                    while k < m and sij + nums[k] + nums[m] > target: m -= 1
                    if k == m: break
                    if sij + nums[k] + nums[m] == target: res.append([nums[i], nums[j], nums[k], nums[m]])
                    kk = k + 1
                    while kk < m and nums[kk] == nums[k]: kk += 1
                    k = kk
                jj = j + 1
                while jj < l - 2 and nums[jj] == nums[j]: jj += 1
                j = jj
            ii = i + 1
            while ii < l - 3 and nums[ii] == nums[i]: ii += 1
            i = ii
        return res

if __name__ == '__main__':
    print Solution().fourSum([1], 0)

