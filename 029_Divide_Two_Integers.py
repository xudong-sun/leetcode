'''
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
'''

class Solution(object):
    def divide(self, dividend, divisor):
        if divisor == 0: return 0x7fffffff
        sign = -1 if (dividend > 0) ^ (divisor > 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)
        res, d = 0, 1
        while (divisor << 1) <= dividend:
            divisor <<= 1
            d <<= 1
        while d > 0:
            if dividend >= divisor:
                dividend -= divisor
                res += d
            divisor >>= 1
            d >>= 1
        res *= sign
        if res > 0x7fffffff or res < -0x80000000: return 0x7fffffff
        return res

if __name__ == '__main__':
    print Solution().divide(40000, 5000)

