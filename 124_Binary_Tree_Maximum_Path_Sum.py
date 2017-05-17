'''
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def maxPathSum(self, root):
        def work(root):
            '''recursive method
            return: tuple[int], max_path, max_path_containing_root
            '''
            left = (0, 0) if root.left is None else work(root.left)
            right = (0, 0) if root.right is None else work(root.right)
            return max(left[0], right[0], max(left[1], 0) + max(right[1], 0) + root.val), max(left[1], right[1], 0) + root.val
        def max_node(root):
            m = root.val
            if root.left: m = max(m, max_node(root.left))
            if root.right: m = max(m, max_node(root.right))
            return m
        if root is None: return 0
        ans = work(root)[0]
        if ans == 0: ans = max_node(root)
        return ans

if __name__ == '__main__':
    tree = generate_tree([1,2,3])
    print Solution().maxPathSum(tree)
    tree = generate_tree([1,-2,3])
    print Solution().maxPathSum(tree)
    tree = generate_tree([1,-2,-3])
    print Solution().maxPathSum(tree)
    tree = generate_tree([-1,-2,-3])
    print Solution().maxPathSum(tree)
    tree = generate_tree([-1,2,-3])
    print Solution().maxPathSum(tree)
    tree = generate_tree([-1, 1, 4, 2, 3, 5, -1])
    print Solution().maxPathSum(tree)
    tree = generate_tree([-10, 1, 4, 2, 3, 5, -1])
    print Solution().maxPathSum(tree)
    tree = generate_tree([-1, 1, 4, 2, 3, -5, -1])
    print Solution().maxPathSum(tree)
    tree = generate_tree([])
    print Solution().maxPathSum(tree)

