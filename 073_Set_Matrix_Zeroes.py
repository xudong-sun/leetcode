'''
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
'''


# space O(1) solution: store row states in the first col; col states in the first row (except col0, store it in extra space)
class Solution(object):
    def setZeroes(self, matrix):
        col0 = False
        m = len(matrix)
        if m == 0: return matrix
        n = len(matrix[0])
        if n == 0: return matrix
        # col0
        for i in range(m):
            if matrix[i][0] == 0:
                col0 = True
                break
        # check the rest
        for i in range(m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        # recover
        for j in range(1, n):
            if matrix[0][j] == 0:
                for i in range(1, m): matrix[i][j] = 0
        for i in range(m):
            if matrix[i][0] == 0:
                for j in range(1, n): matrix[i][j] = 0
        if col0:
            for i in range(m): matrix[i][0] = 0

if __name__ == '__main__':
    m = [[1,0,3],[0,5,6],[7,8,9]]
    Solution().setZeroes(m)
    print(m)

