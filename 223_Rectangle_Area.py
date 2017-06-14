'''
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Assume that the total area is never beyond the maximum possible value of int.
'''


class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        a = max(min(C, G) - max(A, E), 0)
        b = max(min(D, H) - max(B, F), 0)
        return (C-A) * (D-B) + (G-E) * (H-F) - a * b

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(Solution().computeArea(-3,0,3,4,0,-1,9,2), 45)
        self.assertEqual(Solution().computeArea(0,-1,9,2,-3,0,3,4), 45)
    def test2(self):
        self.assertEqual(Solution().computeArea(-2,-2,2,2,-2,-2,2,2), 16)
    def test3(self):
        self.assertEqual(Solution().computeArea(0,0,3,3,1,1,2,2), 9)
    def test4(self):
        self.assertEqual(Solution().computeArea(0,0,1,1,1,0,2,1), 2)
    def test5(self):
        self.assertEqual(Solution().computeArea(0,0,1,1,0,2,1,3), 2)

if __name__ == '__main__':
    unittest.main()

