'''
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
'''

class Solution(object):
    def spiralOrder(self, matrix):
        m = len(matrix)
        if m == 0: return []
        n = len(matrix[0])
        if n == 0: return []
        total = m * n
        visited = [[False] * n for _ in range(m)]
        direction_map = ((0, 1), (1, 0), (0, -1), (-1, 0))
        x = y = direction = 0
        result = [matrix[0][0]]
        visited[0][0] = True
        while len(result) < total:
            flag = False
            xx, yy = x + direction_map[direction][0], y + direction_map[direction][1]
            if xx < 0 or xx >= m or yy < 0 or yy >= n or visited[xx][yy]:
                direction = (direction + 1) % 4
                xx, yy = x + direction_map[direction][0], y + direction_map[direction][1]
            x, y = xx, yy
            result.append(matrix[x][y])
            visited[x][y] = True
        return result

if __name__ == '__main__':
    print(Solution().spiralOrder([[1,2],[3,4],[5,6]]))


