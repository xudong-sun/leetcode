'''
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?
'''


class Solution:
    def reverseBits(self, n):
        ans = 0
        z = 1 << 31
        while n > 0:
            if n & 1 == 1: ans |= z
            n >>= 1
            z >>= 1
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().reverseBits(43261596), 964176192)
    def test2(self):
        self.assertEqual(Solution().reverseBits(0), 0)
    def test3(self):
        self.assertEqual(Solution().reverseBits(0xffffffff), 0xffffffff)

if __name__ == '__main__':
    unittest.main()

