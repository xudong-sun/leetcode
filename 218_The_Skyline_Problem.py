'''
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 <= Li, Ri <= INT_MAX, 0 < Hi <= INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
'''


# Solution 1: segment tree, O(nlogn)
class SegmentTreeNode(object):
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.boundary = l, r  # range [l, r)
        self.maxval = 0       # maximum value in this range
        self.flag = True      # if "maxval" covers the entire range (works like "delay flag" in segment tree)
                              # specifically, if flag is True, then the entire [l,r) range has value "maxval"
                              # additionally, the values in its left and right children have no meanings
class Solution(object):
    def getSkyline(self, buildings):
        ll = len(buildings)
        if not ll: return []
        # map x to inds
        allx = set()
        for l, r, h in buildings:
            allx.add(l)
            allx.add(r)
        allx = sorted(allx)
        map_x_to_idx = {}
        for i,x in enumerate(allx): map_x_to_idx[x] = i
        # build segment tree
        def build_tree(l, r):
            node = SegmentTreeNode(l, r)
            if l+1 < r:
                m = (l + r) / 2
                node.left = build_tree(l, m)
                node.right = build_tree(m, r)
            return node
        #def print_tree(node):
        #    print node.boundary, node.maxval, node.flag
        #    if node.left: print_tree(node.left)
        #    if node.right: print_tree(node.right)
        def add_to_tree(val, x, y, node):
            if node is None: return
            if node.flag and val <= node.maxval: return
            l, r = node.boundary
            if x == l and y == r and node.flag:
                node.maxval = val
                node.flag = True
            else:
                m = (l + r) / 2
                if m >= y: add_to_tree(val, x, y, node.left)
                elif m <= x: add_to_tree(val, x, y, node.right)
                else:
                    add_to_tree(val, x, m, node.left)
                    add_to_tree(val, m, y, node.right)
                if node.flag:
                    add_to_tree(node.maxval, l, m, node.left)
                    add_to_tree(node.maxval, m, r, node.right)
                node.maxval = max(node.maxval, val)
                node.flag = False
        tree = build_tree(0, len(allx)-1)
        for l, r, h in buildings:
            l, r = map_x_to_idx[l], map_x_to_idx[r]
            add_to_tree(h, l, r, tree)
        # collect result
        res = []
        def collect_result(node):
            if node.flag: res.append([node.boundary[0], node.maxval])
            else:
                if node.left: collect_result(node.left)
                if node.right: collect_result(node.right)
        collect_result(tree)
        # remove consecutive equal values
        retval = [[allx[res[0][0]], res[0][1]]]
        for x, h in res[1:]:
            if h != retval[-1][1]: retval.append([allx[x], h])
        retval.append([allx[-1], 0])
        return retval

import unittest
class Test(unittest.TestCase):
    def test1(self):
        buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
        skyline = [[2,10], [3,15], [7,12], [12,0], [15,10], [20,8], [24,0]]
        self.assertEqual(Solution().getSkyline(buildings), skyline)
    def test2(self):
        buildings = [[2,9,10]]
        skyline = [[2,10],[9,0]]
        self.assertEqual(Solution().getSkyline(buildings), skyline)

if __name__ == '__main__':
    unittest.main()

