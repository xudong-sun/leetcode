'''
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 <= k <= BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def kthSmallest(self, root, k):
        count = 0
        stack = []
        node = root
        while True:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            count += 1
            if count == k: return node.val
            node = node.right
        assert False

import unittest
class Test(unittest.TestCase):
    def test1(self):
        tree = generate_tree([3,1,4,None,2])
        for k in xrange(1, 5): self.assertEqual(Solution().kthSmallest(tree, k), k)

if __name__ == '__main__':
    unittest.main()

