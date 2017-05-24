'''
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def postorderTraversal(self, root):
        ans = []
        if root is None: return ans
        stack = [(root, False)]
        while len(stack) > 0:
            node, flag = stack.pop()
            if flag or (node.left is None and node.right is None):
                ans.append(node.val)
            else:
                stack.append((node, True))
                if node.right: stack.append((node.right, False))
                if node.left: stack.append((node.left, False))
        return ans

if __name__ == '__main__':
    tree = generate_tree([1, None, 2, None, None, 3])
    print Solution().postorderTraversal(tree)
    tree = generate_tree([1,2,3,4,5,6,7])
    print Solution().postorderTraversal(tree)
    tree = generate_tree([1])
    print Solution().postorderTraversal(tree)
    tree = generate_tree([])
    print Solution().postorderTraversal(tree)

