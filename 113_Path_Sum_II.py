'''
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def work(self, root, s):
        if root is None: return
        if root.left is None and root.right is None:
            if s == root.val:
                self.current_result.append(root.val)
                self.result.append(self.current_result[:])
                self.current_result.pop()
            return
        self.current_result.append(root.val)
        if root.left: self.work(root.left, s - root.val)
        if root.right: self.work(root.right, s - root.val)
        self.current_result.pop()
    
    def pathSum(self, root, s):
        self.result = []
        self.current_result = []
        self.work(root, s)
        return self.result

if __name__ == '__main__':
    tree = generate_tree([5,4,8,11,None,13,4,7,2,None,None,None,None,5,1])
    print Solution().pathSum(tree, 22)
    print Solution().pathSum(tree, 21)
    tree = None
    print Solution().pathSum(tree, 0)
    tree = generate_tree([1,2])
    print Solution().pathSum(tree, 0)
    print Solution().pathSum(tree, 3)

