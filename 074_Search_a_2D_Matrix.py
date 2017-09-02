'''
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
'''

# treat it as 1d vector, bin-search
class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        if m == 0: return False
        n = len(matrix[0])
        if n == 0: return False
        val = lambda x: matrix[x // n][x % n]
        l, r = 0, m * n - 1
        while l <= r:
            if l == r: return val(l) == target
            m = (l + r) // 2
            v = val(m)
            if v == target: return True
            elif v > target: r = m - 1
            else: l = m + 1
        return False

import unittest
class Test(unittest.TestCase):
    def test1(self):
        matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]]
        self.assertTrue(Solution().searchMatrix(matrix, 3))
        self.assertTrue(Solution().searchMatrix(matrix, 50))
        self.assertFalse(Solution().searchMatrix(matrix, 8))
        self.assertFalse(Solution().searchMatrix(matrix, 0))
        self.assertFalse(Solution().searchMatrix(matrix, 88))

if __name__ == '__main__':
    unittest.main()
