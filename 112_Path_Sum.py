'''
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def hasPathSum(self, root, s):
        if root is None: return False
        if root.left is None and root.right is None: return s == root.val
        return (bool(root.left) and self.hasPathSum(root.left, s - root.val)) or (bool(root.right) and self.hasPathSum(root.right, s - root.val))

if __name__ == '__main__':
    tree = generate_tree([5,4,8,11,None,13,4,7,2,None,None,None,None,None,1])
    print Solution().hasPathSum(tree, 22)
    print Solution().hasPathSum(tree, 21)
    tree = None
    print Solution().hasPathSum(tree, 0)
    tree = generate_tree([1,2])
    print Solution().hasPathSum(tree, 0)

