'''
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
'''


from structs.singly_linked_list import generate_list

class Solution(object):
    def rotateRight(self, head, k):
        # first pass: find length
        node, l = head, 0
        while node != None:
            node = node.next
            l += 1
        if l == 0: return head
        k = k % l
        if k == 0: return head
        # second pass
        fast = head
        while k > 0: 
            fast = fast.next
            k -= 1
        slow = head
        while fast.next != None:
            slow = slow.next
            fast = fast.next
        retval = slow.next
        slow.next = None
        fast.next = head
        return retval

if __name__ == '__main__':
    l = generate_list([1,2,3])
    print Solution().rotateRight(l, 2)

