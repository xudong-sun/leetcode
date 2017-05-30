'''
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
'''


class Solution(object):
    def convertToTitle(self, n):
        z, q = 26, 1
        while n > z:
            n -= z
            z *= 26
            q += 1
        n -= 1
        ans = [''] * q
        for i in xrange(q):
            n, ans[q-1-i] = n / 26, chr(n % 26 + 65)
        return ''.join(ans)

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().convertToTitle(1), 'A')
        self.assertEqual(Solution().convertToTitle(26), 'Z')
    def test2(self):
        self.assertEqual(Solution().convertToTitle(27), 'AA')
        self.assertEqual(Solution().convertToTitle(52), 'AZ')
        self.assertEqual(Solution().convertToTitle(53), 'BA')
        self.assertEqual(Solution().convertToTitle(702), 'ZZ')
    def test3(self):
        self.assertEqual(Solution().convertToTitle(703), 'AAA')
        self.assertEqual(Solution().convertToTitle(1379), 'BAA')
    def test4(self):
        self.assertEqual(Solution().convertToTitle(123456), 'FZPH')
    def test5(self):
        self.assertEqual(Solution().convertToTitle(2147483647), 'FXSHRXW')

if __name__ == '__main__':
    unittest.main()

