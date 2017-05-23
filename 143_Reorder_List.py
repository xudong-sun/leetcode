'''
Given a singly linked list L: L0->L1->...->Ln-1->Ln,
reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
'''


from structs.singly_linked_list import generate_list, ListNode

class Solution(object):
    def reorderList(self, head):
        dummy = ListNode(0)
        dummy.next = head
        # pass 1: find mid-point
        slow, fast = dummy, head
        while fast is not None:
            slow = slow.next
            fast = fast.next
            if fast is None: break
            fast = fast.next
        # pass 2: reverse mid-point to tail
        node = slow.next
        if node is None: return
        tmp = node.next
        node.next = slow.next = None
        while tmp is not None:
            tmp.next, node, tmp = node, tmp, tmp.next
        # pass 3: intertwine head, node
        l1, l2 = head, node
        while l2 is not None:
            l1.next, l1 = l2, l1.next
            if l1 is None: break
            l2.next, l2 = l1, l2.next

if __name__ == '__main__':
    l = generate_list([1,2,3,4,5])
    Solution().reorderList(l)
    print l
    l = generate_list([1,2,3,4])
    Solution().reorderList(l)
    print l
    l = generate_list([1,2,3])
    Solution().reorderList(l)
    print l
    l = generate_list([1,2])
    Solution().reorderList(l)
    print l
    l = generate_list([1])
    Solution().reorderList(l)
    print l
    l = generate_list([])
    Solution().reorderList(l)
    print l

