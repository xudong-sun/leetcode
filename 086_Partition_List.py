'''
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
'''


from structs.singly_linked_list import generate_list, ListNode

class Solution(object):
    def partition(self, head, x):
        dummy = ListNode(0)
        dummy.next = head
        node = dummy
        while node.next is not None and node.next.val < x: node = node.next
        z = node
        while z.next is not None:
            if z.next.val < x:
                zz = z.next
                z.next = zz.next
                zz.next = node.next
                node.next = zz
                node = zz
            else:
                z = z.next
        return dummy.next

if __name__ == '__main__':
    l = generate_list([])
    print Solution().partition(l, 5)

