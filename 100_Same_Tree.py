'''
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def isSameTree(self, p, q):
        if p is None and q is None: return True
        elif p is None or q is None: return False
        else: return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

if __name__ == '__main__':
    t1 = generate_tree([1, 2, 3])
    t2 = generate_tree([1, 2, None, None, 3])
    print Solution().isSameTree(t1, t2)

