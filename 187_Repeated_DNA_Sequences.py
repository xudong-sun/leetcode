'''
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
'''


class Solution(object):
    def __init__(self):
        self.bitmap = {'A': 0, 'C': 1, 'G': 2, 'T': 3}
        self.decodemap = {0: 'A', 1: 'C', 2: 'G', 3: 'T'}
    def findRepeatedDnaSequences(self, s):
        appear = set()
        dup = set()
        if len(s) <= 10: return []
        # compress the first 10 letters
        sub = 0
        for ch in s[:10]:
            sub = (sub << 2) + self.bitmap[ch]
        appear.add(sub)
        # for the remaining sequence
        mask = 262143 # 18 1's
        for ch in s[10:]:
            sub = ((sub & mask) << 2) + self.bitmap[ch]
            if sub in appear: dup.add(sub)
            appear.add(sub)
        # decode
        ans = []
        for code in dup:
            s = [''] * 10
            for i in xrange(10):
                s[9-i] = self.decodemap[code & 3]
                code >>= 2
            ans.append(''.join(s))
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertItemsEqual(Solution().findRepeatedDnaSequences('AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT'), ['AAAAACCCCC', 'CCCCCAAAAA'])
    def test2(self):
        self.assertItemsEqual(Solution().findRepeatedDnaSequences('AAAAAAAAAAAA'), ['AAAAAAAAAA'])
    def test3(self):
        self.assertItemsEqual(Solution().findRepeatedDnaSequences('AAAAAAAAAA'), [])

if __name__ == '__main__':
    unittest.main()

