'''
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
'''

class Solution(object):
    def generateMatrix(self, n):
        if n == 0: return []
        result = [[0] * n for _ in range(n)]
        visited = [[False] * n for _ in range(n)]
        total = n * n
        direction_map = ((0, 1), (1, 0), (0, -1), (-1, 0))
        x = y = direction = 0
        result[0][0] = 1
        i = 2
        visited[0][0] = True
        while i <= total:
            flag = False
            xx, yy = x + direction_map[direction][0], y + direction_map[direction][1]
            if xx < 0 or xx >= n or yy < 0 or yy >= n or visited[xx][yy]:
                direction = (direction + 1) % 4
                xx, yy = x + direction_map[direction][0], y + direction_map[direction][1]
            x, y = xx, yy
            result[x][y] = i
            visited[x][y] = True
            i += 1
        return result

if __name__ == '__main__':
    print(Solution().generateMatrix(4))


