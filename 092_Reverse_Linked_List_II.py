'''
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 <= m <= n <= length of list.
'''

from structs.singly_linked_list import generate_list, ListNode

class Solution(object):
    def reverseBetween(self, head, m, n):
        dummy = ListNode(0)
        dummy.next = head
        start = dummy
        n -= m
        while m > 1: 
            start = start.next
            m -= 1
        end = snx = start.next
        nx = end.next
        while n > 0:
            pre = end
            end = nx
            nx = nx.next
            end.next = pre
            n -= 1
        start.next = end
        snx.next = nx
        return dummy.next

if __name__ == '__main__':
    l = generate_list([1,2,3,4,5])
    print Solution().reverseBetween(l, 1, 2)


