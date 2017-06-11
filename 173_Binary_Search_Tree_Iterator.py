'''
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
'''


# c.f. binary tree in-order traversal (iterative method)

from structs.binary_tree import generate_tree

class BSTIterator(object):
    def __init__(self, root):
        self.stack = []
        if root:
            self.stack.append(root)
            node = root
            while node.left:
                node = node.left
                self.stack.append(node)

    def hasNext(self):
        return bool(self.stack)

    def next(self):
        this_node = self.stack.pop()
        if this_node.right:
            node = this_node.right
            self.stack.append(node)
            while node.left:
                node = node.left
                self.stack.append(node)
        return this_node.val

import unittest
class Test(unittest.TestCase):
    def test1(self):
        tree = generate_tree([2,1,4,None,None,3])
        it, v = BSTIterator(tree), []
        while it.hasNext(): v.append(it.next())
        self.assertEqual(v, [1,2,3,4])
    def test2(self):
        it = BSTIterator(None)
        self.assertFalse(it.hasNext())

if __name__ == '__main__':
    unittest.main()

