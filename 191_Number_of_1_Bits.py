'''
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer '11' has binary representation 00000000000000000000000000001011, so the function should return 3.
'''


class Solution(object):
    def hammingWeight(self, n):
        ans = 0
        while n > 0:
            if n & 1 == 1: ans += 1
            n >>= 1
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().hammingWeight(11), 3)
    def test2(self):
        self.assertEqual(Solution().hammingWeight(0), 0)
    def test3(self):
        self.assertEqual(Solution().hammingWeight(0xffffffff), 32)

if __name__ == '__main__':
    unittest.main()

