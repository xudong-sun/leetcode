'''
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
'''


class Solution(object):
    def climbStairs(self, n):
        if n == 1: return 1
        a = [1] * n
        a[0:2] = 1, 2
        for i in range(2, n): a[i] = a[i-1] + a[i-2]
        return a[n-1]

if __name__ == '__main__':
    print(Solution().climbStairs(1))

