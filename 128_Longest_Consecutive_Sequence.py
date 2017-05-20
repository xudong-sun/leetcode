'''
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
'''


class Solution(object):
    def longestConsecutive(self, nums):
        nums = set(nums)
        ans = 0
        for num in nums:
            if num-1 not in nums:
                l, v = 1, num + 1
                while v in nums:
                    l += 1
                    v += 1
                ans = max(ans, l)
        return ans

if __name__ == '__main__':
    print Solution().longestConsecutive([100, 4, 200, 1, 3, 2])
    print Solution().longestConsecutive([])
    print Solution().longestConsecutive([1])
    print Solution().longestConsecutive([-0x80000000, -0x7fffffff, 0x7fffffff])

