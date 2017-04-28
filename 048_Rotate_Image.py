'''
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
'''


class Solution(object):
    def rotate(self, matrix):
        n = len(matrix)
        rotation_group = lambda x,y: ((x, y), (y, n-x-1), (n-x-1, n-y-1), (n-y-1, x))
        for x in range(n//2):
            for y in range((n+1)//2):
                g = rotation_group(x, y)
                matrix[g[0][0]][g[0][1]], matrix[g[1][0]][g[1][1]], matrix[g[2][0]][g[2][1]], matrix[g[3][0]][g[3][1]] = \
                        matrix[g[3][0]][g[3][1]], matrix[g[0][0]][g[0][1]], matrix[g[1][0]][g[1][1]], matrix[g[2][0]][g[2][1]]

if __name__ == '__main__':
    matrix = [[1]]
    Solution().rotate(matrix)
    print(matrix)

