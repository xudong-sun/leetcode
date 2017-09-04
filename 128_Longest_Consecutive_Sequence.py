'''
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
'''

# Solution 1: a very smart solution using set, O(n), 49ms
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

# Solution 2: union find, O(n), 69ms
# `left` and `right` are mappings: num -> left_boundary, right_boundary
class Solution(object):
    def longestConsecutive(self, nums):
        l = len(nums)
        left, right, longest = {}, {}, 0
        def union_find_left(num):
            if num-1 in left:
                v = union_find_left(left[num-1])
                left[num] = v
                return v
            else: return num
        def union_find_right(num):
            if num+1 in right:
                v = union_find_right(right[num+1])
                right[num] = v
                return v
            else: return num
        for num in nums:
            x, y = union_find_left(num), union_find_right(num)
            longest = max(longest, y - x + 1)
            left[num], right[num] = x, y
        return longest

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().longestConsecutive([100, 4, 200, 1, 3, 2]), 4)
    def test2(self):
        self.assertEqual(Solution().longestConsecutive([5,8,3,9,1,-2,4,0,-1]), 4)
    def test3(self):
        self.assertEqual(Solution().longestConsecutive([]), 0)
    def test4(self):
        self.assertEqual(Solution().longestConsecutive([1]), 1)
    def test5(self):
        self.assertEqual(Solution().longestConsecutive([-0x80000000, -0x7fffffff, 0x7fffffff]), 2)
    def test6(self):
        l = range(10000)
        import random
        random.shuffle(l)
        self.assertEqual(Solution().longestConsecutive(l), 10000)

if __name__ == "__main__":
    unittest.main()

