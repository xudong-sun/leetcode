'''
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def maxDepth(self, root):
        if root is None: return 0
        level = [root]
        ans = 0
        while len(level) > 0:
            ans += 1
            nx_level = []
            for node in level:
                if node.left: nx_level.append(node.left)
                if node.right: nx_level.append(node.right)
            level = nx_level
        return ans

if __name__ == '__main__':
    tree = generate_tree([3, 9, 20, None, None, 15, 7])
    print Solution().maxDepth(tree)
    tree = generate_tree([1,2,None,3])
    print Solution().maxDepth(tree)
    tree = generate_tree([1])
    print Solution().maxDepth(tree)
    tree = None
    print Solution().maxDepth(tree)
