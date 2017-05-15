'''
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def inorderTraversal(self, root):
        stack = []
        res = []
        while True:
            while root:
                stack.append(root)
                root = root.left
            if len(stack) == 0: break
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res

if __name__ == '__main__':
    tree = generate_tree([1, None, 2, None, None, 3])
    print Solution().inorderTraversal(tree)
    tree = generate_tree([1, 2, None, 3, 5, None, None, 4])
    print Solution().inorderTraversal(tree)
    tree = generate_tree([1])
    print Solution().inorderTraversal(tree)
    tree = None
    print Solution().inorderTraversal(tree)

