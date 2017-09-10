'''
Given an integer, write a function to determine if it is a power of two.
'''

# Solution 1
class Solution(object):
    def isPowerOfTwo(self, n):
        if (n <= 0):
            return False
        while (n > 1):
            if n % 2 == 1:
                return False
            n /= 2
        return True

# Solution 2
class Solution(object):
    def isPowerOfTwo(self, n):
        return n > 0 and n & (n-1) == 0

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertFalse(Solution().isPowerOfTwo(96))
    def test2(self):
        self.assertTrue(Solution().isPowerOfTwo(1))
    def test3(self):
        self.assertFalse(Solution().isPowerOfTwo(-2))
    def test4(self):
        self.assertFalse(Solution().isPowerOfTwo(0))
    def test5(self):
        for i in xrange(20):
            self.assertTrue(Solution().isPowerOfTwo(1 << i))

if __name__ == '__main__':
    unittest.main()
