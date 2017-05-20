'''
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
'''


import random

class RandomListNode(object):
     def __init__(self, x):
         self.label = x
         self.next = None
         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        if head is None: return None
        mapping = {}
        node = head
        pre_node = RandomListNode(0)
        while node is not None:
            new_node = RandomListNode(node.label)
            mapping[node] = new_node
            pre_node.next = new_node
            pre_node = new_node
            node = node.next
        node = head
        while node is not None:
            mapping[node].random = None if node.random is None else mapping[node.random]
            node = node.next
        return mapping[head]

def print_list(head):
    while head:
        print head, head.label
        head = head.next

if __name__ == '__main__':
    l = 7
    nodes = [RandomListNode(i+1) for i in xrange(l)]
    for i in xrange(l-1): nodes[i].next = nodes[i+1]
    for i in xrange(l):
        j = random.randint(0, l)
        nodes[i].random = None if j == l else nodes[j]
    print_list(nodes[0])
    copied = Solution().copyRandomList(nodes[0])
    print '-'*20
    print_list(copied)

