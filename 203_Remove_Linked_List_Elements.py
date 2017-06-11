'''
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
'''


from structs.singly_linked_list import generate_list, ListNode

class Solution(object):
    def removeElements(self, head, val):
        dummy = ListNode(val+1)
        dummy.next = head
        node = dummy
        while node.next:
            if node.next.val == val: node.next = node.next.next
            else: node = node.next
        return dummy.next

import unittest
class Test(unittest.TestCase):
    def test1(self):
        l1 = generate_list([1,2,6,3,4,5,6])
        l2 = generate_list([1,2,3,4,5])
        self.assertEqual(str(Solution().removeElements(l1, 6)), str(l2))

if __name__ == '__main__':
    unittest.main()

