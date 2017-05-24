'''
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
'''


from structs.binary_tree import generate_tree

class Solution(object):
    def flatten(self, root):
        def walk(root): # return the flattened head, tail
            if root.left:
                head, tail = walk(root.left)
                root.left = None
                tail.right, root.right = root.right, head
                if tail.right:
                    _, tail = walk(tail.right)
                    return root, tail
                else: return root, tail
            elif root.right: 
                _, tail = walk(root.right)
                return root, tail
            else: return root, root
        if root is None: return None
        walk(root)

if __name__ == '__main__':
    tree = generate_tree([1,2,5,3,4,None,6])
    Solution().flatten(tree)
    print tree
    tree = generate_tree([1,2,3,4])
    Solution().flatten(tree)
    print tree
    tree = generate_tree([1,2,None,3,None,None,None,4])
    Solution().flatten(tree)
    print tree
    tree = generate_tree([1])
    Solution().flatten(tree)
    print tree
    tree = generate_tree([])
    Solution().flatten(tree)
    print tree

