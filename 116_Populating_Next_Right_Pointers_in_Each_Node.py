'''
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
'''


from Queue import Queue

class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None
    def _line(self):
        return str(self.val) if self.next is None else str(self.val) + ' -> ' + self.next._line()
    def __str__(self):
        return self._line() if self.left is None else self._line() + '\n' + str(self.left)

def generate_tree(nodes):
    l = len(nodes)
    if l == 0: return None
    n = [None if val is None else TreeLinkNode(val) for val in nodes]
    for i in xrange(1, l):
        if n[i]:
            parent = n[(i-1) / 2]
            assert parent, 'invalid binary tree'
            if i % 2 == 1: parent.left = n[i]
            else: parent.right = n[i]
    return n[0]

'''
# O(n) space, level-order traversal
class Solution:
    def connect(self, root):
        if root is None: return
        q = Queue()
        q.put(root)
        nullpos = 0
        idx = 0
        pre = None
        while q.qsize() > 0:
            node = q.get()
            if idx == nullpos:
                nullpos = (nullpos << 1) + 1
            else:
                pre.next = node
            if node.left: q.put(node.left)
            if node.right: q.put(node.right)
            pre = node
            idx += 1
'''
# O(1) space
class Solution:
    def connect(self, root):
        if root is None: return
        while root.left:
            cur = root
            while cur:
                cur.left.next = cur.right
                if cur.next: cur.right.next = cur.next.left
                cur = cur.next
            root = root.left

if __name__ == '__main__':
    tree = generate_tree([1,2,3,4,5,6,7])
    Solution().connect(tree)
    print tree
    tree = generate_tree([1,2,3])
    Solution().connect(tree)
    print tree
    tree = generate_tree([1])
    Solution().connect(tree)
    print tree
    tree = generate_tree([])
    Solution().connect(tree)
    print tree

