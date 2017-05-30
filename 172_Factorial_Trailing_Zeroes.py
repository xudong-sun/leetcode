'''
Given an integer n, return the number of trailing zeroes in n!.
'''


class Solution(object):
    def trailingZeroes(self, n):
        ans = 0
        z = 5
        while z <= n:
            ans += n / z
            z *= 5
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        for i in xrange(1, 11):
            self.assertEqual(Solution().trailingZeroes(i), i/5)
    def test2(self):
        self.assertEqual(Solution().trailingZeroes(25), 6)
    def test3(self):
        self.assertEqual(Solution().trailingZeroes(0), 0)
    def test4(self):
        self.assertEqual(Solution().trailingZeroes(2147483647), 536870902)

if __name__ == '__main__':
    unittest.main()

