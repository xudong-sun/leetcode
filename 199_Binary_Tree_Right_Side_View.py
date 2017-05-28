'''
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def rightSideView(self, root):
        ans = []
        if root is None: return ans
        level = [root]
        while level:
            ans.append(level[0].val)
            next_level = []
            for node in level:
                if node.right: next_level.append(node.right)
                if node.left: next_level.append(node.left)
            level = next_level
        return ans

import unittest
class Test(unittest.TestCase):
    def test1(self):
        tree = generate_tree([1,2,3,None,5,None,4])
        self.assertEqual(Solution().rightSideView(tree), [1,3,4])
    def test2(self):
        tree = generate_tree([1,2,None,3,None,None,None,4,5])
        self.assertEqual(Solution().rightSideView(tree), [1,2,3,5])
    def test3(self):
        tree = generate_tree([1])
        self.assertEqual(Solution().rightSideView(tree), [1])
    def test4(self):
        self.assertEqual(Solution().rightSideView(None), [])

if __name__ == '__main__':
    unittest.main()

