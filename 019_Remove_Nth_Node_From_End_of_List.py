'''
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
'''

from structs.singly_linked_list import generate_list

class Solution(object):
    def removeNthFromEnd(self, head, n):
        fast = slow = head
        for _ in xrange(n): fast = fast.next
        if not fast: # n == len(list)
            return head.next
        while True:
            fast = fast.next
            if fast: slow = slow.next
            else:
                slow.next = slow.next.next
                break
        return head

if __name__ == '__main__':
    l = generate_list([1, 2])
    print Solution().removeNthFromEnd(l, 2)

