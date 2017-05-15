'''
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
'''


class Solution(object):
    def minimumTotal(self, triangle):
        l = len(triangle)
        if l == 0: return 0
        if l == 1: return triangle[0][0]
        a = [triangle[0][0]]
        for i in range(1, l):
            a.append(a[-1] + triangle[i][-1])
            for j in range(i-1, 0, -1): a[j] = min(a[j], a[j-1]) + triangle[i][j]
            a[0] = a[0] + triangle[i][0]
        return min(a)

if __name__ == '__main__':
    print(Solution().minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))
    print(Solution().minimumTotal([[2]]))
    print(Solution().minimumTotal([]))

