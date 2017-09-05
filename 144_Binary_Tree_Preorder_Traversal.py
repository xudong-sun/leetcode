'''
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
'''


from structs.binary_tree import generate_tree

# Here's two solutions, both using stack
# Solution 1
class Solution(object):
    def preorderTraversal(self, root):
        ans = []
        if root is None: return ans
        stack = []
        stack.append(root)
        while len(stack) > 0:
            node = stack.pop()
            ans.append(node.val)
            if node.right: stack.append(node.right)
            if node.left: stack.append(node.left)
        return ans

# Solution 2
class Solution(object):
    def preorderTraversal(self, root):
        ans, stack = [], []
        node = root
        while True:
            while node:
                ans.append(node.val)
                stack.append(node)
                node = node.left
            if len(stack) == 0: break
            node = stack.pop().right
        return ans


if __name__ == '__main__':
    tree = generate_tree([1, None, 2, None, None, 3])
    print Solution().preorderTraversal(tree)
    tree = generate_tree([1,2,3,4,5,6,7])
    print Solution().preorderTraversal(tree)
    tree = generate_tree([1])
    print Solution().preorderTraversal(tree)
    tree = generate_tree([])
    print Solution().preorderTraversal(tree)

