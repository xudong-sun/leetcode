'''
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
'''

from structs.singly_linked_list import ListNode, generate_list

class Solution(object):
    def swapPairs(self, head):
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy
        while cur.next and cur.next.next:
            n1 = cur.next
            n2 = n1.next
            cur.next = n2
            cur = n2.next
            n2.next = n1
            n1.next = cur
            cur = n1
        return dummy.next

if __name__ == '__main__':
    l = generate_list([])
    print Solution().swapPairs(l)



