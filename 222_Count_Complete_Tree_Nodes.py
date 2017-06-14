'''
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def countNodes(self, root):
        def height(root):
            h = 0
            while root:
                h += 1
                root = root.left
            return h
        ans = 0
        while root:
            if root.left is None:
                ans += 1
                break
            elif root.right is None:
                ans += 2
                break
            h1, h2 = height(root.left), height(root.right)
            if h1 == h2:
                ans += 1 << (h1-1) + 1
                root = root.right
            else:
                ans += 1 << (h2-1) + 1
                root = root.left
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        import random
        for _ in xrange(100):
            n = random.randint(2, 10000)
            tree = generate_tree(range(n))
            self.assertEqual(Solution().countNodes(tree), n)
    def test2(self):
        tree = generate_tree([1])
        self.assertEqual(Solution().countNodes(tree), 1)
    def test3(self):
        self.assertEqual(Solution().countNodes(None), 0)

if __name__ == '__main__':
    unittest.main()

