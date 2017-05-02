'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
'''


class Solution(object):
    def minPathSum(self, grid):
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        if n == 0: return 0
        a = [[0] * n for _ in range(m)]
        a[0][0] = grid[0][0]
        for j in range(1, n): a[0][j] = a[0][j-1] + grid[0][j]
        for i in range(1, m): a[i][0] = a[i-1][0] + grid[i][0]
        for i in range(1, m):
            for j in range(1, n):
                a[i][j] = min(a[i-1][j], a[i][j-1]) + grid[i][j]
        return a[m-1][n-1]

if __name__ == '__main__':
    print(Solution().minPathSum([[1,2]]))

