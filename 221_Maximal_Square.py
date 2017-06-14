'''
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
'''


class Solution(object):
    def maximalSquare(self, matrix):
        m = len(matrix)
        if m == 0: return 0
        n = len(matrix[0])
        if n == 0: return 0
        a = [[0] * n for _ in xrange(m)]
        ans = 0
        for i in xrange(m):
            a[i][0] = int(matrix[i][0])
            if a[i][0] == 1: ans = 1
        for j in xrange(n):
            a[0][j] = int(matrix[0][j])
            if a[0][j] == 1: ans = 1
        for i in xrange(1, m):
            for j in xrange(1, n):
                if matrix[i][j] == '1':
                    a[i][j] = min(a[i-1][j-1], a[i-1][j], a[i][j-1]) + 1
                    ans = max(ans, a[i][j])
        return ans * ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        matrix = ['10100', '10111', '11111', '10010']
        self.assertEqual(Solution().maximalSquare(matrix), 4)
    def test2(self):
        matrix = ['11000', '11111', '01111', '01111', '01111']
        self.assertEqual(Solution().maximalSquare(matrix), 16)
    def test3(self):
        matrix = ['11000', '11111', '01111', '01111', '01110']
        self.assertEqual(Solution().maximalSquare(matrix), 9)
    def test4(self):
        matrix = ['00', '00', '00']
        self.assertEqual(Solution().maximalSquare(matrix), 0)

if __name__ == '__main__':
    unittest.main()

