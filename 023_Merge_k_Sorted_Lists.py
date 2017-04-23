'''
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
'''

from Queue import PriorityQueue
from structs.singly_linked_list import ListNode, generate_list

class Solution(object):
    def mergeKLists(self, lists):
        q = PriorityQueue()
        for l in lists:
            if l: q.put((l.val, l))
        head = tail = ListNode(0)
        while True:
            try: _, l = q.get(block=False)
            except: break
            tail.next = l
            tail = l
            l = l.next
            if l: q.put((l.val, l))
        return head.next

if __name__ == '__main__':
    l1 = generate_list([0])
    l2 = generate_list([1, 2])
    l3 = generate_list([])
    print Solution().mergeKLists([l1])

