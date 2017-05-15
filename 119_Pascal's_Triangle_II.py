'''
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
'''


class Solution(object):
    def getRow(self, rowIndex):
        res = [1]
        if rowIndex == 0: return res
        for i in range(1, rowIndex+1):
            for j in range(i-1, 0, -1): res[j] += res[j-1]
            res.append(1)
        return res

if __name__ == '__main__':
    print(Solution().getRow(0))

