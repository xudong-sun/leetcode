'''
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
'''


# count number of 1 appearing in each digit
# 123: (24)+2*10+13*1=57
# 213: 1*100+(2*10+4)+22*1=146

class Solution(object):
    def countDigitOne(self, n):
        if n <= 0: return 0
        ans = 0
        base, mult = 10, 1
        while mult <= n:
            x, y = n / base, n % base
            y, z = y / mult, y % mult
            if y > 1: ans += (x+1) * mult
            elif y == 1: ans += x * mult + (z+1)
            else: ans += x * mult
            base *= 10
            mult *= 10
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().countDigitOne(13), 6)
    def test2(self):
        for i in xrange(1, 10): self.assertEqual(Solution().countDigitOne(i), 1)
    def test3(self):
        self.assertEqual(Solution().countDigitOne(123), 57)
    def test4(self):
        self.assertEqual(Solution().countDigitOne(213), 146)
    def test5(self):
        self.assertEqual(Solution().countDigitOne(2017), 1610)
    def test6(self):
        self.assertEqual(Solution().countDigitOne(10000), 4001)
    def test7(self):
        self.assertEqual(Solution().countDigitOne(11111), 5560)
    def test8(self):
        self.assertEqual(Solution().countDigitOne(0), 0)

if __name__ == '__main__':
    unittest.main()

