'''
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
'''


# DP, backward
# hp[i][j]: minimum hp for the knight to live at grid i,j, and able to save the princess
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        m, n = len(dungeon), len(dungeon[0])
        hp = [[1] * n for _ in xrange(m)]
        hp[-1][-1] = max(1 - dungeon[-1][-1], 1)
        for i in xrange(m-2, -1, -1): hp[i][-1] = max(hp[i+1][-1] - dungeon[i][-1], 1)
        for j in xrange(n-2, -1, -1): hp[-1][j] = max(hp[-1][j+1] - dungeon[-1][j], 1)
        for i in xrange(m-2, -1, -1):
            for j in xrange(n-2, -1, -1):
                hp[i][j] = max(min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j], 1)
        return hp[0][0]

import unittest
class Test(unittest.TestCase):
    def test1(self):
        dungeon = [[-2, -3, 3], [-5, -10, 1], [10, 30, -5]]
        hp = Solution().calculateMinimumHP(dungeon)
        self.assertEqual(hp, 7)
    def test2(self):
        self.assertEqual(Solution().calculateMinimumHP([[10]]), 1)

if __name__ == '__main__':
    unittest.main()

