'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
'''

'''
# O(n^2): TLE
class Solution(object):
    def threeSum(self, nums):
        one = set()
        two = {}
        three = []
        for num in nums:
            if -num in two:
                for x1 in two[-num]:
                    x2 = -num - x1
                    if num < x1: three.append([num, x1, x2])
                    elif num > x2: three.append([x1, x2, num])
                    else: three.append([x1, num, x2])
            for o in one:
                s = o + num
                t = min(o, num)
                if s in two: two[s].add(t)
                else: two[s] = {t}
            one.add(num)
        if len(three) == 0: return []
        three.sort()
        return [l for i, l in enumerate(three[:-1]) if l != three[i+1]] + [three[-1]]
'''

# two-pointer solution
# O(N^2)
class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        res = []
        l = len(nums)
        i = 0
        while i < l:
            if nums[i] > 0: break
            j, k = i + 1, l - 1
            while j < k:
                while j < k and nums[k] > -nums[i]-nums[j]: k -= 1
                if j == k: break
                if nums[i] + nums[j] + nums[k] == 0: res.append([nums[i], nums[j], nums[k]])
                jj = j + 1
                while jj < k and nums[jj] == nums[j]: jj += 1
                j = jj
            ii = i + 1
            while ii < l and nums[ii] == nums[i]: ii += 1
            i = ii
        return res

if __name__ == '__main__':
    print Solution().threeSum([0, 0, 0, 0])

