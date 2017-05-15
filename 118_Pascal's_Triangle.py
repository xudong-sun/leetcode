'''
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
'''


class Solution(object):
    def generate(self, numRows):
        res = []
        if numRows == 0: return res
        res.append([1])
        for i in range(1, numRows):
            a = [1]
            for j in range(1, i): a.append(res[-1][j-1] + res[-1][j])
            a.append(1)
            res.append(a)
        return res

if __name__ == '__main__':
    print(Solution().generate(10))

