'''
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def sumNumbers(self, root):
        def walk(root, val):
            val = val * 10 + root.val
            if root.left is None and root.right is None: return val
            res = 0
            if root.left: res += walk(root.left, val)
            if root.right: res += walk(root.right, val)
            return res
        if root is None: return 0
        else: return walk(root, 0)

if __name__ == '__main__':
    tree = generate_tree([1,2,3])
    print Solution().sumNumbers(tree)
    tree = generate_tree([1])
    print Solution().sumNumbers(tree)
    tree = generate_tree([1,2])
    print Solution().sumNumbers(tree)
    tree = None
    print Solution().sumNumbers(tree)
    tree = generate_tree([1,2,3,4])
    print Solution().sumNumbers(tree)

