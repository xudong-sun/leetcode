'''
Implement pow(x, n).
'''

class Solution(object):
    def myPow(self, x, n):
        sign, n = n >= 0, abs(n)
        result = 1
        while True:
            if n & 1: result *= x
            n >>= 1
            if n == 0: break
            x *= x
        if not sign: result = 1 / result
        return result

if __name__ == '__main__':
    print(Solution().myPow(0.1, -4))

