'''
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
'''


# Topological sort

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        inNodes = [0] * numCourses
        outNodes = [[] for _ in xrange(numCourses)]
        for o, i in prerequisites:
            inNodes[o] += 1
            outNodes[i].append(o)
        stack = []
        for x in xrange(numCourses):
            if inNodes[x] == 0: stack.append(x)
        count = 0
        while stack:
            x = stack.pop()
            count += 1
            for o in outNodes[x]:
                inNodes[o] -= 1
                if inNodes[o] == 0: stack.append(o)
        return count == numCourses

import unittest
class Test(unittest.TestCase):
    def test1(self):
        self.assertTrue(Solution().canFinish(2, [[1,0]]))
    def test2(self):
        self.assertFalse(Solution().canFinish(2, [[1,0],[0,1]]))
    def test3(self):
        self.assertTrue(Solution().canFinish(2, []))
    def test4(self):
        self.assertTrue(Solution().canFinish(0, []))
    def test5(self):
        self.assertFalse(Solution().canFinish(4, [[1,0],[1,2],[2,3],[3,1]]))

if __name__ == '__main__':
    unittest.main()


