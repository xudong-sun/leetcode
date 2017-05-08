'''
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
'''


class Solution(object):
    def isSameTree(self, p, q):
        if p is None and q is None: return True
        elif p is None or q is None: return False
        else: return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)



