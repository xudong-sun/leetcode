'''
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
'''


class Solution(object):
    def maximalRectangle(self, matrix):
        m = len(matrix)
        if m == 0: return 0
        n = len(matrix[0])
        if n == 0: return 0
        heights = [0] * (n+1)
        ans = 0
        for i in xrange(m):
            for j in xrange(n):
                heights[j] = 0 if matrix[i][j] == '0' else heights[j] + 1
            stack = [-1]
            for j in xrange(n + 1):
                while heights[stack[-1]] > heights[j]:
                    idx = stack.pop()
                    sq = heights[idx] * (j - stack[-1] - 1)
                    ans = max(ans, sq)
                stack.append(j)
        return ans

if __name__ == '__main__':
    matrix = ['10100', '10111', '11111', '10010']
    print Solution().maximalRectangle(matrix)
    matrix = ['']
    print Solution().maximalRectangle(matrix)
    matrix = ['01110', '11111', '11111', '11111', '00110']
    print Solution().maximalRectangle(matrix)

