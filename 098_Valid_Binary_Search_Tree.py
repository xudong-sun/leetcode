'''
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def isValidBST(self, root):
        def is_valid(root, left, right):
            if root is None: return True
            val_check = (left is None or root.val > left) and (right is None or root.val < right)
            return val_check and is_valid(root.left, left, root.val) and is_valid(root.right, root.val, right)
        return is_valid(root, None, None)

if __name__ == '__main__':
    tree = generate_tree([2,1,3])
    print Solution().isValidBST(tree)
    tree = generate_tree([1,2,3])
    print Solution().isValidBST(tree)
    tree = generate_tree([1])
    print Solution().isValidBST(tree)
    tree = None
    print Solution().isValidBST(tree)
    tree = generate_tree([2,1,4,None,None,1,5])
    print Solution().isValidBST(tree)
    tree = generate_tree([0x7fffffff])
    print Solution().isValidBST(tree)

