'''
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
'''


class Solution(object):
    def __init__(self):
        self.sums = [1, 3, 6, 10, 15, 21, 28, 36, 45]
    def combinationSum3(self, k, n):
        def walk(level, target, m, result):
            if level == k:
                if target == 0: return [result[:]]
                else: return []
            if m == 0: return []
            if target > self.sums[m-1]: return []
            if target < self.sums[k-level-1]: return []
            ans = []
            ans += walk(level+1, target-m, m-1, result[:]+[m])
            ans += walk(level, target, m-1, result)
            return ans
        return [list(reversed(l)) for l in walk(0, n, 9, [])]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertItemsEqual(Solution().combinationSum3(3, 7), [[1,2,4]])
    def test2(self):
        self.assertItemsEqual(Solution().combinationSum3(3, 9), [[1,2,6],[1,3,5],[2,3,4]])
    def test3(self):
        self.assertItemsEqual(Solution().combinationSum3(1, 7), [[7]])
    def test4(self):
        self.assertEqual(Solution().combinationSum3(10, 55), [])
        self.assertEqual(Solution().combinationSum3(0, 7), [])
        self.assertEqual(Solution().combinationSum3(3, 5), [])

if __name__ == '__main__':
    unittest.main()

