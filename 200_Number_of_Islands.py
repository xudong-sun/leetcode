'''
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
'''


class Solution(object):
    def numIslands(self, grid):
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        if n == 0: return 0
        visited = [[False] * n for _ in xrange(m)]
        stack = []
        def dfs():
            while len(stack) > 0:
                x, y = stack.pop()
                visited[x][y] = True
                if x-1 >= 0 and grid[x-1][y] == '1' and not visited[x-1][y]: stack.append((x-1, y))
                if x+1 < m and grid[x+1][y] == '1' and not visited[x+1][y]: stack.append((x+1, y))
                if y-1 >= 0 and grid[x][y-1] == '1' and not visited[x][y-1]: stack.append((x, y-1))
                if y+1 < n and grid[x][y+1] == '1' and not visited[x][y+1]: stack.append((x, y+1))
        total = 0
        for i in xrange(m):
            for j in xrange(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    total += 1
                    stack.append((i, j))
                    dfs()
        return total

import unittest
class Test(unittest.TestCase):
    def test1(self):
        grid = ['11110','11010','11000','00000']
        self.assertEqual(Solution().numIslands(grid), 1)
    def test2(self):
        grid = ['11000','11000','00100','00011']
        self.assertEqual(Solution().numIslands(grid), 3)
    def test3(self):
        self.assertEqual(Solution().numIslands(['1']), 1)
    def test4(self):
        self.assertEqual(Solution().numIslands(['0']), 0)

if __name__ == '__main__':
    unittest.main()

