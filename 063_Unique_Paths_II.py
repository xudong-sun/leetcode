'''
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
'''


class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        if m == 0: return 0
        n = len(obstacleGrid[0])
        if n == 0: return 0
        a = [[0] * n for _ in range(m)]
        for j in range(n):
            if obstacleGrid[0][j] == 0: a[0][j] = 1
            else: break
        for i in range(m):
            if obstacleGrid[i][0] == 0: a[i][0] = 1
            else: break
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0: a[i][j] = a[i-1][j] + a[i][j-1]
        return a[m-1][n-1]

if __name__ == '__main__':
    print(Solution().uniquePathsWithObstacles([[0,0,0],[0,0,0],[0,0,1]]))

