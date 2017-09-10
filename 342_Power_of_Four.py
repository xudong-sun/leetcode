'''
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
    Given num = 16, return true. Given num = 5, return false.

    Follow up: Could you solve it without loops/recursion?
'''

class Solution(object):
    def isPowerOfFour(self, num):
        return num > 0 and num & (num-1) == 0 and num & 0x55555555 != 0

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertTrue(Solution().isPowerOfFour(16))
        self.assertFalse(Solution().isPowerOfFour(8))
        self.assertTrue(Solution().isPowerOfFour(1))
        self.assertFalse(Solution().isPowerOfFour(0))
        self.assertFalse(Solution().isPowerOfFour(-16))
    def test2(self):
        def checker(num):
            if num <= 0: return False
            while num > 1:
                if num % 4 != 0: return False
                num /= 4
            return True
        import random
        for _ in xrange(10000):
            num = random.randint(1, 0x7fffffff)
            self.assertEqual(Solution().isPowerOfFour(num), checker(num))

if __name__ == "__main__":
    unittest.main()

