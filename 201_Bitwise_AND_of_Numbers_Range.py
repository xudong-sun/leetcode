'''
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
'''


class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        nn, tmp = n, 1
        while nn > 1:
            nn >>= 1
            tmp <<= 1
        ans = 0
        while tmp > 0:
            if tmp & m & n > 0: ans += tmp
            elif (tmp & m) ^ (tmp & n): break
            tmp >>= 1
        return ans

'''
# a better solution: keep removing the rightest '1' in n, until n <= m
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        while m < n: n = n & (n-1)
        return n;
'''

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().rangeBitwiseAnd(5, 7), 4)
    def test2(self):
        self.assertEqual(Solution().rangeBitwiseAnd(5, 8), 0)
    def test3(self):
        self.assertEqual(Solution().rangeBitwiseAnd(5, 5), 5)
    def test4(self):
        self.assertEqual(Solution().rangeBitwiseAnd(10, 11), 10)
    def test5(self):
        self.assertEqual(Solution().rangeBitwiseAnd(0, 0), 0)
    def test6(self):
        self.assertEqual(Solution().rangeBitwiseAnd(1, 2147483647), 0)

if __name__ == '__main__':
    unittest.main()

