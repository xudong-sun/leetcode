'''
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
'''


from structs.binary_tree import generate_tree, TreeNode

class Solution(object):
    def generateTrees(self, n):
        def generate(x, y):
            if x > y: return [None]
            elif x == y: return [TreeNode(x)]
            res = []
            for m in xrange(x, y+1):
                left = generate(x, m-1)
                right = generate(m+1, y)
                for l in left:
                    for r in right:
                        head = TreeNode(m)
                        head.left, head.right = l, r
                        res.append(head)
            return res
        if n == 0: return []
        else: return generate(1, n)

if __name__ == '__main__':
    trees = Solution().generateTrees(2)
    for tree in trees: print tree

