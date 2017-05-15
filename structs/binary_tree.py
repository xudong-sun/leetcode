class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    def __str__(self):
        return str(self.val) + ', ' + str(self.left) + ', ' + str(self.right)

def generate_tree(nodes):
    '''generate a binary tree
    nodes: list
    return: head of a binary tree
    '''
    l = len(nodes)
    if l == 0: return None
    n = [None if val is None else TreeNode(val) for val in nodes]
    for i in xrange(1, l):
        if n[i]:
            parent = n[(i-1) / 2]
            assert parent, 'invalid binary tree'
            if i % 2 == 1: parent.left = n[i]
            else: parent.right = n[i]
    return n[0]

