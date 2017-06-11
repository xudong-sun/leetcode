'''
Reverse a singly linked list.
'''


from structs.singly_linked_list import generate_list

class Solution(object):
    def reverseList(self, head):
        if head is None: return None
        n1, n2 = head, head.next
        while n2:
            n2.next, n1, n2 = n1, n2, n2.next
        head.next = None
        return n1

import unittest
class Test(unittest.TestCase):
    def test1(self):
        l1 = generate_list([1,2,3,4,5])
        l2 = generate_list([5,4,3,2,1])
        self.assertEqual(str(Solution().reverseList(l1)), str(l2))
    def test2(self):
        l = generate_list([1])
        self.assertEqual(str(Solution().reverseList(l)), str(l))
    def test3(self):
        self.assertIsNone(Solution().reverseList(None))

if __name__ == '__main__':
    unittest.main()

