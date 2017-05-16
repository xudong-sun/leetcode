'''
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def zigzagLevelOrder(self, root):
        res = []
        if root is None: return res
        level = [root]
        i = 0
        while len(level) > 0:
            i += 1
            nx_level = []
            a = []
            for node in level:
                a.append(node.val)
                if node.left: nx_level.append(node.left)
                if node.right: nx_level.append(node.right)
            if i % 2 == 0: a.reverse()
            res.append(a)
            level = nx_level
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

