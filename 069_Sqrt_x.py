'''
Implement int sqrt(int x).

Compute and return the square root of x.
'''


class Solution(object):
    def mySqrt(self, x):
        if x <= 1: return x
        l, r = 0, x
        while l + 1 < r:
            m = l + (r-l)//2
            m2 = m * m
            if m2 == x: return m
            elif m2 < x: l = m
            else: r = m
        return l

if __name__ == '__main__':
    for i in range(20):
        print(Solution().mySqrt(i))

