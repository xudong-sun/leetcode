'''
Given an integer, write a function to determine if it is a power of three.

Follow up:
    Could you do it without using any loop / recursion?
'''

# Solution 1
class Solution(object):
    def isPowerOfThree(self, n):
        return n > 0 and 1162261467 % n == 0

# Solution 2
# log_3(n) is an integer
import math
class Solution(object):
    def isPowerOfThree(self, n):
        return n > 0 and abs((math.log(n) / math.log(3) + 0.5) % 1 - 0.5) < 1e-10

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertFalse(Solution().isPowerOfThree(18))
    def test2(self):
        ans = [Solution().isPowerOfThree(x) for x in xrange(10)]
        self.assertEqual(ans, [False, True, False, True, False, False, False, False, False, True])
    def test3(self):
        self.assertFalse(Solution().isPowerOfThree(-3))
    def test4(self):
        for i in xrange(10):
            self.assertTrue(Solution().isPowerOfThree(3 ** i))

if __name__ == "__main__":
    unittest.main()
