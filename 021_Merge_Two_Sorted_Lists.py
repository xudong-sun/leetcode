'''
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
'''

from structs.singly_linked_list import generate_list

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if l1 is None: return l2
        if l2 is None: return l1
        if l1.val < l2.val:
            head = tail = l1
            l1 = l1.next
        else:
            head = tail = l2
            l2 = l2.next
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                tail = l1
                l1 = l1.next
            else:
                tail.next = l2
                tail = l2
                l2 = l2.next
        if l1 is None: tail.next = l2
        elif l2 is None: tail.next = l1
        return head

if __name__ == '__main__':
    l1 = generate_list([1])
    l2 = generate_list([])
    print Solution().mergeTwoLists(l1, l2)


