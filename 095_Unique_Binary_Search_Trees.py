'''
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''


class Solution(object):
    def numTrees(self, n):
        a = [1, 1]
        for i in xrange(2, n+1):
            x = 0
            for j in xrange(i):
                x += a[j] * a[i-j-1]
            a.append(x)
        return a[-1]

if __name__ == '__main__':
    print Solution().numTrees(3)

