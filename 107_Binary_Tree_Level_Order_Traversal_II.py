'''
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def levelOrderBottom(self, root):
        res = []
        if root is None: return res
        level = [root]
        while len(level) > 0:
            nx_level = []
            a = []
            for node in level:
                a.append(node.val)
                if node.left: nx_level.append(node.left)
                if node.right: nx_level.append(node.right)
            res.append(a)
            level = nx_level
        res.reverse()
        return res

if __name__ == '__main__':
    tree = generate_tree([3, 9, 20, None, None, 15, 7])
    print Solution().levelOrder(tree)
    tree = generate_tree([1,2,None,3])
    print Solution().levelOrder(tree)
    tree = generate_tree([1])
    print Solution().levelOrder(tree)
    tree = None
    print Solution().levelOrder(tree)

