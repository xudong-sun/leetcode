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


class Solution(object):
    def searchMatrix(self, matrix, target):
        m = len(matrix)
        if m == 0: return False
        n = len(matrix[0])
        if n == 0: return False
        # binsearch col-wise
        if target < matrix[0][0] or target > matrix[m-1][n-1]: return False
        l, r = 0, m
        while l+1 < r:
            mid = l + (r-l)//2
            if matrix[mid][0] == target: return True
            elif matrix[mid][0] < target: l = mid
            else: r = mid
        # binsearch row-wise
        x, l, r = l, 0, n-1
        while l <= r:
            mid = l + (r-l)//2
            if matrix[x][mid] == target: return True
            elif matrix[x][mid] < target: l = mid + 1
            else: r = mid - 1
        return False

if __name__ == '__main__':
    print(Solution().searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,50]], 15))

