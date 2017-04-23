'''
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
'''

from structs.singly_linked_list import ListNode, generate_list

class Solution(object):
    def reverseKGroup(self, head, k):
        if k < 2: return head
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy
        while True:
            node = cur
            for _ in xrange(k):
                node = node.next
                if node is None: break
            if node is None: break
            n1 = cur.next
            n2 = n1.next
            n3 = n2.next
            while True:
                n2.next = n1
                if n2 is node: break
                n1, n2, n3 = n2, n3, n3.next
            n1 = cur.next
            n1.next = n3
            cur.next = n2
            cur = n1
        return dummy.next

if __name__ == '__main__':
    l = generate_list([])
    print Solution().reverseKGroup(l, 2)

