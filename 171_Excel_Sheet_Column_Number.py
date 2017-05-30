'''
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
'''


# checkout 168_Excel_Sheet_Column_Title
# This is the simplified calculation
class Solution(object):
    def titleToNumber(self, s):
        l = len(s)
        ans = 0
        z = 1
        for i in xrange(l):
            ans += z * (ord(s[l-1-i]) - 65)
            ans += z
            z *= 26
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().titleToNumber('A'), 1)
        self.assertEqual(Solution().titleToNumber('Z'), 26)
    def test2(self):
        self.assertEqual(Solution().titleToNumber('AA'), 27)
        self.assertEqual(Solution().titleToNumber('AZ'), 52)
        self.assertEqual(Solution().titleToNumber('BA'), 53)
        self.assertEqual(Solution().titleToNumber('ZZ'), 702)
    def test3(self):
        self.assertEqual(Solution().titleToNumber('AAA'), 703)
        self.assertEqual(Solution().titleToNumber('BAA'), 1379)
    def test4(self):
        self.assertEqual(Solution().titleToNumber('FZPH'), 123456)
    def test5(self):
        self.assertEqual(Solution().titleToNumber('FXSHRXW'), 2147483647)

if __name__ == '__main__':
    unittest.main()

