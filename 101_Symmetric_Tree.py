'''
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def isSymmetric(self, root):
        def is_symmetric(left_tree, right_tree):
            if left_tree is None and right_tree is None: return True
            elif left_tree is None or right_tree is None: return False
            else: return left_tree.val == right_tree.val and is_symmetric(left_tree.left, right_tree.right) and is_symmetric(left_tree.right, right_tree.left)
        if root is None: return True
        return is_symmetric(root.left, root.right)

if __name__ == '__main__':
    tree = generate_tree([1,2,2,3,4,4,3])
    print Solution().isSymmetric(tree)
    tree = generate_tree([1,2,2,None,3,None,3])
    print Solution().isSymmetric(tree)
    tree = generate_tree([1])
    print Solution().isSymmetric(tree)
    tree = None
    print Solution().isSymmetric(tree)
    tree = generate_tree([1,2])
    print Solution().isSymmetric(tree)

