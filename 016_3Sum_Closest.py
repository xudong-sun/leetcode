'''
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution(object):
    def threeSumClosest(self, nums, target):
        nums.sort()
        l = len(nums)
        res = sum(nums[:3])
        def try_ijk(i, j, k, res):
            s = nums[i] + nums[j] + nums[k]
            if abs(s - target) < abs(res - target): res = s
            return res
        i = 0
        while i < l:
            if nums[i] * 3 > target and nums[i] * 3 > res: break
            j, k = i + 1, l - 1
            while j < k:
                while j < k and nums[i] + nums[j] + nums[k] > target: k -= 1
                if j == k:
                    if j < l - 1: res = try_ijk(i, j, j+1, res)
                    break
                res = try_ijk(i, j, k, res)
                if k < l - 1: res = try_ijk(i, j, k+1, res)
                if res == target: return res
                jj = j + 1
                while jj < k and nums[jj] == nums[j]: jj += 1
                j = jj
            ii = i + 1
            while ii < l and nums[ii] == nums[i]: ii += 1
            i = ii
        return res

if __name__ == '__main__':
    print Solution().threeSumClosest([-1, 3, 1, 1, 1, -4], 2)



